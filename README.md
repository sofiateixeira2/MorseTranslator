# Morse Translator

 A c++ program that can translate normal text to morse code and can translate morse code to normal text. It's a simple program made when I got some spare time and wanted to write something in c++ to practice.

 The program runs in both Linux and Windows (if you have a cpp compiler instaled).

## How to compile

To complie the program you need to be at the root directory of the repository, ```\MorseTranslator\``` , and run the following command:

```
$ g++ -o translator translator.cpp
```

## How to run

To run the program you just need to be at the same directory and run:

```
$ .\translator
```

## To do:
Although it's quite a simple program, my goal it's to make it super complete with all the features that I can think of. Maybe in the future, I will use this code to make a simple app for morse translation as a way to train app development.

To do so, there are some features that I would like to add:
- Find a way to do jumps in the code (after I translate something, there will be an option asking if I want to translate anything else and if so, jump to the begining of the code).
- Fix bugs.

### List of known bugs:
- Morse code to text:
  - Need to write ' ' after every morse code word or else the program throws an error.
  - When writing multiple lines in standard input, the program does not write '/n'. This implies that the translation in the ouput file will be all in one line.
