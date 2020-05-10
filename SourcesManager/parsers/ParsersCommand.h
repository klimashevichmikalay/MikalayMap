#ifndef PARSERSCOMMAND_H
#define PARSERSCOMMAND_H

#include "JsonCommand.h"
#include "map"

enum PARSER_TYPE { JSON };

class ParsersCommand {
 public:
  ParsersCommand() {
    parsers.insert(pair<PARSER_TYPE, ICommand *>(JSON, new JsonCommand()));
  }

  ICommand *getParser(PARSER_TYPE _type) {
    iterator = parsers.find(_type);
    if (iterator != parsers.end()) {
      return iterator->second;
    } else
      return nullptr;
  }

 private:
  std::map<PARSER_TYPE, ICommand *> parsers;
  std::map<PARSER_TYPE, ICommand *>::iterator iterator;
};

#endif  // PARSERSCOMMAND_H
