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


## Documentação das rotas

### Front end (porta 80)

#### Página inicial

```
GET /
```

| Parâmetro | Tipo  | Obrigatorio | Descrição |
|-----------|-------|-------------|-----------|
| Nenhum | - | - | Retorna a página `index.html` da pasta `Front-end`. |

Se o arquivo `/Front-end/index.html` não existir, retorna:
```
Status 404: Pagina home nao existe (adicione um arquivo "index.html" na pasta "PATH_FRONT_END").
```

Se ocorrer tudo certo retorna:
```
Status 200: Envia o arquivo "/PATH_FRONT_END/index.html"
```

#### Rota Not Found

```
GET /{path}
```

| Parâmetro | Tipo  | Obrigatorio | Descrição |
|-----------|-------|-------------|-----------|
| {path} | String | Sim | Usa o `{path}` como caminho para um arquivo no cartão SD. |

Se o caminho `{path}` não corresponder a um arquivo dentro de `PATH_FRONT_END` retorna:
```
Status 404: {path} nao encontrado
```

Se ocorrer tudo certo retorna:
```
Status 200: Envia o arquivo html encontrado em "PATH_FRONT_END/{path}"
```

### Back end (porta 4242)

#### Rota get imagem

```
GET /img/{}
```

| Parâmetro | Tipo  | Obrigatorio | Descrição |
|-----------|-------|-------------|-----------|
| {file} | String | Sim | Nome da imagem a ser buscado dentro de "/PATH_BACK_END/img/". |

Se `{file}` não for passado, retorna:
```
Status 400: Nome do arquivo ou diretório ausente.
```

Se a imagem `{file}` não corresponder a um arquivo dentro de `/PATH_FRONT_END/img/` retorna:
```
Status 404: {file} nao encontrado
```

Se ocorrer tudo certo retorna:
```
Status 200: Envia a imagem encontrado em "PATH_BACK_END/img/{file}"
```

#### Rota get json

```
GET /json/{}
```

| Parâmetro | Tipo  | Obrigatorio | Descrição |
|-----------|-------|-------------|-----------|
| {file} | String | Sim | Nome do json a ser buscado dentro de "/PATH_BACK_END/json/". |

Se `{file}` não for passado, retorna:
```
Status 400: Nome do arquivo ou diretório ausente.
```

Se a imagem `{file}` não corresponder a um arquivo dentro de `/PATH_FRONT_END/json/` retorna:
```
Status 404: {file} nao encontrado
```

Se ocorrer tudo certo retorna:
```
Status 200: Envia o json encontrado em "PATH_BACK_END/json/{file}"
```

#### Rota get pdf

```
GET /pdf/{}
```

| Parâmetro | Tipo  | Obrigatorio | Descrição |
|-----------|-------|-------------|-----------|
| {file} | String | Sim | Nome do pdf a ser buscado dentro de "/PATH_BACK_END/pdf/". |

Se `{file}` não for passado, retorna:
```
Status 400: Nome do arquivo ou diretório ausente.
```

Se a imagem `{file}` não corresponder a um arquivo dentro de `/PATH_FRONT_END/pdf/` retorna:
```
Status 404: {file} nao encontrado
```

Se ocorrer tudo certo retorna:
```
Status 200: Envia o pdf encontrado em "PATH_BACK_END/pdf/{file}"
```

#### Rota upload img

```
GET upload/img/{}
```

| Parâmetro | Tipo  | Obrigatorio | Descrição |
|-----------|-------|-------------|-----------|
| name | String | Sim | Nome dado ao arquivo carregado. |

Se `name` não for passado, retorna:
```
Status 400: Nome do arquivo ausente.
```

Se já existir uma imagem com esse mesmo nome e extensão no mesmo diretório restorna:
```
Status 409: Arquivo com este nome ja existente.
```

Se ocorrer tudo certo retorna:
```
Status 200: Salva a imagem em "PATH_BACK_END/upload/img/{file}" e envia apenas o status.
```

#### Rota upload json

```
GET upload/json/{}
```

| Parâmetro | Tipo  | Obrigatorio | Descrição |
|-----------|-------|-------------|-----------|
| name | String | Sim | Nome dado ao arquivo carregado. |

Se `name` não for passado, retorna:
```
Status 400: Nome do arquivo ausente.
```

Se já existir um json com esse mesmo nome e extensão no mesmo diretório restorna:
```
Status 409: Arquivo com este nome ja existente.
```

Se ocorrer tudo certo retorna:
```
Status 200: Salva o json em "PATH_BACK_END/upload/json/{file}" e envia apenas o status.
```

#### Rota upload pdf

```
GET upload/pdf/{}
```

| Parâmetro | Tipo  | Obrigatorio | Descrição |
|-----------|-------|-------------|-----------|
| name | String | Sim | Nome dado ao arquivo carregado. |

Se `name` não for passado, retorna:
```
Status 400: Nome do arquivo ausente.
```

Se já existir um pdf com esse mesmo nome e extensão no mesmo diretório restorna:
```
Status 409: Arquivo com este nome ja existente.
```

Se ocorrer tudo certo retorna:
```
Status 200: Salva o pdf em "PATH_BACK_END/upload/pdf/{file}" e envia apenas o status.
```