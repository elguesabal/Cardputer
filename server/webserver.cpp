#include "header.h"

// FUNCAO CRIADA PARA SUPRIR TEMPORARIAMENTE A NECESSIDADE DE UM FUNCAO DE Q COPIE ATE UM DETERMINADO ELEMENTO (TO SEM NET E NAO DA PRA PESQUISAR)
String cute(const String &url) {
    String urlReturn;
    
    for (unsigned int i = 0; url[i] != '?' && url[i] != '\0'; i++) {
        urlReturn += url[i];
    }
    return (urlReturn);
}

/// @brief INICIA A API E DEFINE AS ROTAS
/// @brief COMO AS OUTRAS ROTAS ALEM DO HOME SAO DEFINIDAS PELA EXISTENCIA DE UM ARQUIVO NO SD QUALQUER OUTRA ROTA ACONTECE NO METODO "nNotFound"
void webServerStart(void) {
    webServer.on("/", home);
    webServer.onNotFound(getRoute);
    webServer.begin();
}

/// @brief RESPONDE A ROTA HOME CASO TENHA O ARQUIVO "/Pages/index.html"
void home(void) {
    File file = getFile(String(PATH_DIR) + "/index.html");

    if (!file) {
        webServer.send(404, "text/html", "<p>Erro: Pagina home nao existe (adicione um arquivo html na pasta \"Pages\")</p>");
        return ;
    }
    webServer.streamFile(file, "text/html");
    file.close();
}

/// @brief BUSCA O TIPO DE ARQUIVO COM BASE NO PATH DA REQUISICAO
/// @param path A SER ANALISADO
/// @return RETORNA O TIPO DE RESPOSTA IDEAL PARA A REQUISICAO
String getType(String path) {
    if (path.endsWith(".html")) {
        return ("text/html");
    } else if (path.endsWith(".css")) {
        return ("text/css");
    } else if (path.endsWith(".js")) {
        return ("application/javascript");
    } else if (path.endsWith(".png")) {
        return ("image/png");
    } else if (path.endsWith(".gif")) {
        return ("image/gif");
    } else if (path.endsWith(".jpg")) {
        return ("image/jpeg");
    } else if (path.endsWith(".ico")) {
        return ("image/x-icon");
    } else if (path.endsWith(".xml")) {
        return ("text/xml");
    } else if (path.endsWith(".pdf")) {
        return ("application/pdf");
    } else if (path.endsWith(".zip")) {
        return ("application/zip");
    } else {
        return ("text/plain");
    }
}

/// @brief PROCURA O ARQUIVO (OU PAGINA HTML) SEGUINDO A URL PASSADA NA ROTA E CASO NAO EXISTA O ARQUIVO CITADO ENVIA UMA MENSAGEM DE ERRO
void getRoute(void) {
    String path = PATH_DIR + cute(webServer.uri()) + (cute(webServer.uri()).indexOf(".") == -1 ? ".html" : "");
    String type = getType(path);
    File file = getFile(path);

    if (!file) {
        webServer.send(404, "text/html", "<p>Erro: \"" + webServer.uri() + "\" nao encontrado</p>");
        return ;
    }
    webServer.streamFile(file, type) != file.size();
    // DBG_OUTPUT_PORT.println("Sent less data than expected!"); // NAO ENTENDI MT BEM (PESQUISAR MELHOR DPS)
    file.close();
}