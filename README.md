<h1 align="center">Lexical Analyzer</h1>

<p align="center">
   <img src="https://github.com/Colgate13/LexicalAnalyzer/assets/54006467/f2fe3f29-23c1-467b-af2d-597a378a31b2" alt="lexial" width="400"/>
</p>

<p align="center">	
  <img alt="Repository size" src="https://img.shields.io/github/repo-size/Colgate13/LexicalAnalyzer?color=774DD6">

  <a href="https://github.com/Colgate13/LexicalAnalyzer/commits">
    <img alt="GitHub last commit" src="https://img.shields.io/github/last-commit/Colgate13/LexicalAnalyzer?color=774DD6">
  </a> 
  <img alt="License" src="https://img.shields.io/badge/license-MIT-8257E5">
  <a href="https://github.com/Colgate13/LexicalAnalyzer/stargazers">
    <img alt="Stargazers" src="https://img.shields.io/github/stars/Colgate13/LexicalAnalyzer?color=8257E5&logo=github">
  </a>
</p>

<p align="center">
    <a href="README.md">English</a>
 </p>

 <p align="center">
  <a href="#about">About</a>&nbsp;&nbsp;&nbsp;|&nbsp;&nbsp;&nbsp;
  <a href="#technologies">Technologies</a>&nbsp;&nbsp;&nbsp;|&nbsp;&nbsp;&nbsp;
  <a href="#features">Features</a>&nbsp;&nbsp;&nbsp;|&nbsp;&nbsp;&nbsp;
  <a href="#docs">Docs</a>&nbsp;&nbsp;&nbsp;|&nbsp;&nbsp;&nbsp;
  <a href="#license">License</a>
</p>

## :notebook: About

<div id="about"></div>

This project is an my implementation of a basic lexical analyzer, developed as part of my learning about lexical analysis and automata. The lexical analyzer is a fundamental component of compilers and interpreters, responsible for breaking down the source code into tokens, which are the smallest recognizable units of the programming language.

Implements this automata/state machine
<p align="center">
   <img src="https://github.com/Colgate13/LexicalAnalyzer/assets/54006467/5cbd69e3-6469-40e8-9a7b-2e1500ae2090" alt="lexial" width="400"/>
</p>

## Technologies 🐱‍🏍🎂

<div id="technologies"></div>

- [C](https://www.gnu.org/software/gnu-c-manual/) - C
- [Clang](https://clang.llvm.org/) - C/C++ Compiler
- [Make | Makefile](https://www.gnu.org/software/make/) - Make and Makefile

### Features

<div id="features"></div>

- [x] Open file
- [x] Output files tokens

## Docs
<div id="docs"></div>

### Required
```sh
clang
```

### Build and Run
```sh
git clone https://github.com/Colgate13/LexicalAnalyzer.git
cd LexicalAnalyzer
make
make install # to install the lib binary in /usr/local/

./bin/main ./Utils/example.code
```

## License

<div id="license"></div>

MIT [LICENSE](LICENSE.md)
