# Cardputer WiFi Server

Este repositório contém o código para transformar o **M5Stack Cardputer** em um ponto de acesso WiFi, fornecendo uma interface web armazenada no cartão SD e uma API back-end para interação.

## Visão Geral

O projeto cria um **servidor WiFi** no Cardputer, permitindo que dispositivos conectados acessem:
- **Front-end**: Páginas HTML armazenadas na pasta `Front-end` do cartão SD.
- **Back-end**: API desenvolvida em C++ armazenada na pasta `Back-end` do cartão SD.

## Estrutura do Projeto

```
Cardputer/
├── backEnd.cpp         # Inicia o back end e define rotas
├── cardputer.cpp       # Inicia a parte gráfica
├── front-end.cpp       # Inicia o front end e define rotas
├── header.h            # Arquivos de cabeçalho
├── sdCard.cpp          # Funções de suporte ao cartão SD
├── server.ino          # Arquivo com as funções setup e loop
├── utils.cpp           # Funções auxiliares
└── wifi.cpp            # Inicia o ponto de acesso wifi
```

## Funcionalidades

- **Cria um ponto de acesso WiFi** para conectar dispositivos.
- **Serviço de arquivos**: Serve páginas HTML diretamente do SD.
- **API back-end**: Processa requisições HTTP e retorna respostas dinâmicas.
- **Gerenciamento de conexões**: Permite acesso simultâneo de múltiplos dispositivos.

## Configuração e Compilação

*******

## Uso

1. Conecte-se ao WiFi criado pelo Cardputer.
2. Acesse o front-end via navegador digitando o endereço do servidor.
3. Utilize a API back-end conforme a documentação da API.
