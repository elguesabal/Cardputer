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
    String path = PATH_DIR;
    std::string html = getPage(path + "/index.html").c_str();

    if (!html.empty()) {
        webServer.send(200, "text/html", html.c_str());
    } else {
        webServer.send(404, "text/html", "<p>Erro: Pagina home nao existe (adicione um arquivo html na pasta \"Pages\")</p>");
    }
}

/// @brief PROCURA O ARQUIVO SEGUINDO A URL PASSADA NA ROTA E CASO NAO EXISTA O ARQUIVO CITADO ENVIA UMA MENSAGEM DE ERRO
void getRoute(void) {
    std::string html = getPage(PATH_DIR + cute(webServer.uri())).c_str();

    if (!html.empty()) {
        webServer.send(200, "text/html", html.c_str());
    } else {
        webServer.send(404, "text/html", "<p>Erro: \"" + webServer.uri() + "\" nao encontrado</p>");
    }
}