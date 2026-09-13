# Sistema de Estoque - Loja de Conveniência

Projeto desenvolvido para a disciplina de Estrutura de Dados, com o objetivo de criar um sistema de gerenciamento de estoque para uma loja de conveniência em linguagem C, aplicando conceitos de Tipos Abstratos de Dados, Alocação Dinâmica de Memória e diferentes tipos de Listas Encadeadas (Simples, Dupla e Circular).

## Integrantes

* Elder Luiz
* Ruan Victor
* Ray Samuel

## Organização dos arquivos

O projeto está dividido em módulos, cada um com seus arquivos `.c` e `.h`, além de um `Makefile` para automação da compilação:

```text
📁 conveny_shop
│
├── 📁 src
│   └── 📄 main.c
│
├── 📁 produto
│   ├── 📄 produto.c
│   └── 📄 produto.h
│
├── 📁 simples
│   ├── 📄 simples.c
│   └── 📄 simples.h
│
├── 📁 dupla
│   ├── 📄 dupla.c
│   └── 📄 dupla.h
│
├── 📁 circular
│   ├── 📄 circular.c
│   └── 📄 circular.h
│
├── 📁 interface
│   ├── 📄 interface.c
│   └── 📄 interface.h
│
├── 📄 Makefile
└── 📄 README.md
```

### `main.c`

É o arquivo responsável pelo fluxo principal do programa.

Nele são realizadas:

* Chamada das funções do sistema;
* Exibição e controle do menu principal e dos submenus;
* `switch-case` responsável pela escolha do usuário;
* Controle do fluxo de execução do programa.

### `interface.c` / `interface.h`

Contém as funções responsáveis pela interface apresentada ao usuário no terminal, como menus, leitura de dados e formatação de saída.

### `simples.c` / `simples.h`
2
Contém a definição da `struct perecivel` e a implementação das operações para a **Lista Simplesmente Encadeada**, utilizada para gerenciar os **Produtos Perecíveis**.

### `dupla.c` / `dupla.h`

Contém a definição da `struct nao_perecivel` e a implementação das operações para a **Lista Duplamente Encadeada**, utilizada para gerenciar os **Produtos Não Perecíveis**.

### `circular.c` / `circular.h`

Contém a definição da `struct promo` e a implementação das operações para a **Lista Circular Simplesmente Encadeada**, utilizada para gerenciar os **Produtos em Promoção**.
### `produto.c` / `produto.h`

Contém a definição do `enum` usado para tratamento de erros.
## Como utilizar

Após compilar e executar o programa, será apresentado um menu principal no terminal com as áreas de gerenciamento disponíveis.

O usuário deverá selecionar uma opção e, em seguida, um submenu com as operações específicas daquela lista será exibido.

**Menu Principal:**
```
===== LOJA DE CONVENIÊNCIAS =====
1. Gerenciar Perecíveis (Simples)
2. Gerenciar Não Perecíveis (Dupla)
3. Gerenciar Promoções (Circular)
0. Sair
>
```

**Submenus (exemplo):**
```
===== PRODUTOS EM PROMOÇÃO =====
1. Adicionar produto
2. Remover produto
3. Buscar produto
4. Listar produtos
5. Editar produto
6. Contar produtos
7. Limpar lista
0. Voltar
>
```

## Funcionalidades

Para cada uma das três listas (Simples, Dupla e Circular), o sistema oferece as seguintes operações:

1. **Inserir no início e no fim:** Adiciona um novo produto na primeira ou na última posição da lista.
2. **Remover do início, do fim e por ID:** Remove um produto da primeira posição, da última posição ou de uma posição específica com base no seu ID.
3. **Buscar por substring no nome:** Localiza e exibe todos os produtos cujo nome contém a substring pesquisada.
4. **Atualizar quantidade:** Modifica a quantidade em estoque de um produto, localizado por seu ID.
5. **Exibir todos os produtos:** Lista todos os produtos da lista, mostrando ID, nome, quantidade e preço.
6. **Exibir reverso:** (Funcionalidade presente **apenas para a lista dupla**) Exibe os produtos na ordem inversa.
7. **Contar produtos:** Informa o número total de produtos presentes na lista.
8. **Esvaziar a lista:** Remove todos os produtos e libera a memória alocada dinamicamente para cada nó da lista.

## Tratamento de Erros

O sistema foi desenvolvido para tratar os seguintes casos de erro:

* Tentativa de operação em **lista vazia**.
* Tentativa de remoção ou atualização com um **ID inexistente**.
* **Falha de alocação de memória** durante a criação de um novo nó.
* **Opções de menu inválidas**.

## Compilação e Execução

O projeto utiliza um `Makefile` para automatizar o processo de compilação. Para compilar todos os arquivos-fonte e gerar o executável, basta executar o seguinte comando no terminal, a partir do diretório raiz do projeto:

```bash
make
```

Após a compilação, um arquivo executável (chamado `run`) será criado. Para executar o programa, use:

```bash
./run
```

Para limpar os arquivos objeto e o executável gerados, utilize:

```bash
make clean
```