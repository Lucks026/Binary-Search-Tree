# Binary Search Tree em C

Estudando estruturas de dados, implementei uma BST do zero. Sem biblioteca externa, só C11. Queria entender de verdade cada caso do remove — folha, um filho, dois filhos via sucessor inorder — não só ler sobre isso.

O projeto tem menu interativo e uma suite de testes pra validar o comportamento.

## Como usar

```bash
make        # compila
make run    # abre o menu interativo
make test   # executa os testes
make clean  # remove os binários
```

## Estrutura

```
bst-c/
├── include/bst.h
├── src/
│   ├── bst.c
│   └── main.c
├── tests/test_bst.c
└── Makefile
```

---

# Binary Search Tree in C

Built this to understand data structures properly, not just read about them. Pure C11, no dependencies.

Covers: insert, search, contains, min/max, inorder/preorder/postorder, remove with all three cases, height, count, print, and free.

```bash
make        # build
make run    # interactive menu
make test   # run test suite
make clean  # remove binaries
```

Author: Lucas — github.com/Lucks026
