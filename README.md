# MModeler

## Fluxo de Trabalho

#### Passo 1) Começando os trabalhos
```
$ git checkout master (ativando no ramo master)     
$ git pull (recuperando a última versão do repositório remoto da equipe)
```

#### Passo 2) Criando um ramo para armazenar as alterações       
```
$ git checkout –b <work_branch> (criando o ramo onde serão feitas as alterações locais)
```

#### Passo 3) Trabalhando...

#### Passo 4) Recuperando as alterações realizadas desde que comecei a trabalhar
```
$ git checkout master (ativando no ramo master)     
$ git pull (recuperando a última versão do repositório remoto da equipe)
```

#### Passo 5) Sincronizando a base do meu ramo de trabalho com as alterações remotas
```
$ git checkout <work_branch> (ativando no ramo <work_branch>)     
$ git rebase master (atualizando a base do ramo <work_branch> com a do master)
```

#### Passo 6) Mesclando as minhas alterações (lembre­‐se de tratar os conflitos, caso existam)
```
$ git checkout master (ativando no ramo master)     
$ git merge <work_branch> (fazendo o merge dos ramos master e <work_branch>)
```

#### Passo 7) Finalmente, enviando minhas alterações para o repositório remoto
```
$ git push origin master (enviando as alterações para o servidor remoto)
```
