# Wave Engine

Wave engine foi criada com o objetivo de ser uma engine simples. Apesar de ainda estar longe disso.

> As informações aqui fornecidas levam em consideração que está usando um sistema operacional `Windows`.

## Dependencias
- raylib
- yaml-cpp

Para instalação recomendo `msys` usando pacman.

``` bash
pacman -S mingw-w64-yaml-cpp
pacman -S mingw-w64-raylib
```

No meu caso o `msys` está em `C:`, portanto, se o seu caso também for este, não é necessario modificar o `Makefile`.

## Build

### Debug

Para construir você pode usar:

``` bash
make
make run
```

A aplicação será compilada e executada.

### Distribuição

Para distribuição será o mesmo processo, com a diferença de que será necessário incluir os arquivos necessários para a execução da aplicação manualmente no mesmo diretorio do executável. Ainda não há um processo automático pra isso.

## Diretórios

- **buid**: Arquivos de build.
- **include**: Bibliotecas locais.
- **resources**: Ativos.
- **src**: Código fonte.

## Licença de uso

Você pode ver a licensa [clicando aqui](LICENSE.MD).