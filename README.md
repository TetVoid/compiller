# EasyXML
Language for easy work with XML

# Author
Viktor Markovec, group: 821703.

## Install ANTLR

### For Linux

``` bash
$ cd /usr/local/lib
$ sudo wget https://www.antlr.org/download/antlr-4.9.1-complete.jar
```
in the end of your bash config file (in Ubuntu it's .bashrc in your user folder) add next lines:
```
export CLASSPATH=".:/usr/local/lib/antlr-4.9.1-complete.jar:$CLASSPATH"
alias antlr4='java -jar /usr/local/lib/antlr-4.9.1-complete.jar'
alias grun='java org.antlr.v4.gui.TestRig'
```
### For Windows
  1. Download [antlr4](https://www.antlr.org/download/antlr-4.9.1-complete.jar).
  1. Add antlr4-complete.jar to CLASSPATH, either:
     1. **Permanently**: 
        > Using System Properties dialog > Environment variables > Create or append to CLASSPATH variable
     1. **Temporarily**, at command line:
      ```cmd 
      SET CLASSPATH=.;C:\Javalib\antlr4-complete.jar;%CLASSPATH%
      ```
  1. Create batch commands for ANTLR Tool, TestRig in dir in PATH
  * `antlr4.bat: java org.antlr.v4.Tool %*`
  * `grun.bat:   java org.antlr.v4.gui.TestRig %*`
  
  ## Generate Lexer, Parser, Listener, Visitor
  
After changing `g4` file you need to regenerate generated module by following commands:

  ```bash 
  $ cd gramma
  $ antlr4 -Dlanguage=Python3 -visitor -no-listener EasyXML.g4 -o ../generated/
  ```
