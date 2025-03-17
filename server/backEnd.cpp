#include "header.h"

/// @brief INICIA O BACK END E DEFINE AS ROTAS
void backEndStart(void) {
    #if !defined(PORT_BACK_END)
        #if defined(M5CARDPUTER)
            M5CARDPUTER.println("Back end nao iniciado");
        #endif
        return ;
    #else
        backEnd = new WebServer(PORT_BACK_END);
    #endif
    routesBackEnd();
    backEnd->begin();
    #if defined(M5CARDPUTER) && defined(PORT_BACK_END)
        M5CARDPUTER.printf("Back end iniciado na porta %d\n", PORT_BACK_END);
    #endif
}

/// @brief INICIA AS ROTAS DO BACK END
void routesBackEnd(void) {
    backEnd->on("/", []() {
        backEnd->send(200, "text/html", "Rota home");
    });
    backEnd->on("/img", getImg);
    backEnd->on("/json", getJson);
    backEnd->on("/upload/img", HTTP_POST, []() { backEnd->send(200, "text/plain", ""); }, uploadFile);
    backEnd->on("/upload/json", HTTP_POST, []() { backEnd->send(200, "text/plain", ""); }, uploadFile);
    backEnd->on("/upload/pdf", HTTP_POST, []() { backEnd->send(200, "text/plain", ""); }, uploadFile);
    backEnd->onNotFound([]() {
        backEnd->send(404, "text/plain", "Erro 404: Rota nao encontrada");
    });
}

/// @brief FUNTAO RESPOSNSAVEL PELA ROTA "/img" 
/// @warning CASO O ARGUMENTO "img" ESTEJA AUSENTE RESPONDE COM O STATUS 400 "BAD REQUEST"
/// @warning CASO O ARQUIVO NAO SEJA ENCONTRADO RESPONDE COM O STATUS 404 "NOT FOUND"
/// @note CASO TUDO OCORRA CORRETAMENTE RESPONDE COM STATUS 200 "OK"
void getImg(void) {
    String img = backEnd->arg("img");
    if (!img.length()) {
        backEnd->send(400, "text/plain", "Erro 400: Parametro \"img\" ausente.");
        return ;
    }
    File file = getFile(PATH_BACK_END + String("/img/") + img);
    if (!file) {
        backEnd->send(404, "text/plain", "Erro 404: Arquivo \"" + img + "\" nao encontrada");
        return ;
    }
    backEnd->streamFile(file, getType(img));
    file.close();
}

/// @brief FUNTAO RESPOSNSAVEL PELA ROTA "/json" 
/// @warning CASO O ARGUMENTO "json" ESTEJA AUSENTE RESPONDE COM O STATUS 400 "BAD REQUEST"
/// @warning CASO O ARQUIVO NAO SEJA ENCONTRADO RESPONDE COM O STATUS 404 "NOT FOUND"
/// @note CASO TUDO OCORRA CORRETAMENTE RESPONDE COM STATUS 200 "OK"
void getJson(void) {
    String json = backEnd->arg("json");
    if (!json.length()) {
        backEnd->send(400, "text/plain", "Erro 400: Parametro \"json\" ausente.");
        return ;
    }
    File file = getFile(PATH_BACK_END + String("/json/") + json);
    if (!file) {
        backEnd->send(404, "text/plain", "Erro 404: Arquivo \"" + json + "\" nao encontrada");
        return ;
    }
    backEnd->streamFile(file, getType(json));
    file.close();
}

/// @brief RECEBE E SALVA UM ARQUIVO NO CARTAO SD
/// @warning CASO O ARGUMENTO "name" ESTEJA AUSENTE RESPONDE COM O STATUS 400 "BAD REQUEST"
/// @warning CASO EXISTA UM ARQUIVO COM O MESMO NOME CITADO POR "name" NA MESMA PASTA RESPONDE COM 409 "CONFLICT"
/// @note CASO TUDO OCORRA SEM ERROS ESTA FUNCAO NAO RESPONDE E SIM ESPERA Q SEJA PASSADO OUTRA FUNCAO DENTRO DO METODO "on" QUE RESPONDA COM STATUS 200
void uploadFile(void) {
    HTTPUpload &upload = backEnd->upload();
    static File file;
    String name = backEnd->arg("name");
    String path = PATH_BACK_END + backEnd->uri().substring(backEnd->uri().lastIndexOf('/')) + "/" + name;

    if (!name.length()) {
        backEnd->send(400, "text/plain", "Erro 400: Campo \"name\" ausente");
        return ;
    }
    if (upload.status == UPLOAD_FILE_START) {
        if (checkPath(path.c_str())) {
            backEnd->send(409, "text/plain", "Erro 409: Arquivo com este nome ja existente");
            return ;
        }
        file = SD.open(path, FILE_WRITE);
    } else if (upload.status == UPLOAD_FILE_WRITE) {
        if (file) {
            file.write(upload.buf, upload.currentSize);
        }
    } else if (upload.status == UPLOAD_FILE_END) {
        if (file) {
            file.close();
        }
    }
}