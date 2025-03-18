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

## Rodando localmente pelo cmd no Windows

Clone o projeto

```bash
  git clone <link do repositório>
```

Entre no diretório do projeto

```bash
  cd <diretório do projeto>
```

Compile o projeto para binário

```bash
  arduino-cli compile --fqbn m5stack:esp32:m5stack_cardputer .
```

Fazendo uploado do binário

```bash
  arduino-cli upload -p COM3 --fqbn m5stack:esp32:m5stack_cardputer .
```

## Uso

1. Conecte-se ao WiFi criado pelo Cardputer.
2. Acesse o front-end via navegador digitando o endereço do servidor.
3. Utilize a API back-end conforme a documentação da API.


## Documentação da API de teste

### Front end

#### Retorna todos os itens

```http
  GET "/"
```

#### Retorna 2 possíveis respostas:

status(200): 
```http
  <arquivo>.html
```

status(404):
```http
  Erro 404: Pagina home nao existe (adicione um arquivo "index.html" na pasta "Back-end\")
```


### Back end