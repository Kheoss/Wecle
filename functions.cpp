#include "mainHeader.hpp"

void Commands::PrintFunction(int& _tokenIndex, std::vector<std::pair<Parser::TokenPrimaryType, std::string> >& _curBlock){

    std::pair<Parser::TokenPrimaryType, std::string> _curToken = _curBlock[_tokenIndex+1];
                    std::string _param = _curToken.second;
                    if(_curToken.first == Parser::VARIABLE){
                        //return the value of variable
                        _param = Parser::GetVariableValue(_curToken.second);
                    }
                    if(_curToken.first == Parser::HARDSTRING){
                    _param = _param.substr(1,_curToken.second.size()-2);
                    }
    
    std::cout<<_param<<"\n";
    _tokenIndex ++;
}
void Commands::BrutCommandFunction(int& _tokenIndex, std::vector<std::pair<Parser::TokenPrimaryType, std::string> >& _curBlock){
    
        std::pair<Parser::TokenPrimaryType, std::string> _curToken = _curBlock[_tokenIndex+1];
                    std::string _param = _curToken.second;
                    if(_curToken.first == Parser::VARIABLE){
                        //return the value of variable
                        _param = Parser::GetVariableValue(_curToken.second);
                    }
                    if(_curToken.first == Parser::HARDSTRING){
                    _param = _param.substr(1,_curToken.second.size()-2);
                    }
    
    
    system(&_param[0]);
    _tokenIndex ++;
    std::cout<<"\n Brut Command used succesfully \n";
}
void Commands::CreateDirFunction(int& _tokenIndex, std::vector<std::pair<Parser::TokenPrimaryType, std::string> >& _curBlock){
    
        std::pair<Parser::TokenPrimaryType, std::string> _curToken = _curBlock[_tokenIndex+1];
                    std::string _param = _curToken.second;
                    if(_curToken.first == Parser::VARIABLE){
                        //return the value of variable
                        _param = Parser::GetVariableValue(_curToken.second);
                    }
                    if(_curToken.first == Parser::HARDSTRING){
                    _param = _param.substr(1,_curToken.second.size()-2);
                    }
    
    
    mkdir(&_param[0]);
    _tokenIndex ++;
}
void Commands::AddFileEventListener(int& _tokenIndex, std::vector<std::pair<Parser::TokenPrimaryType, std::string> >& _curBlock){
    
     std::pair<Parser::TokenPrimaryType, std::string> _curToken = _curBlock[_tokenIndex+1];
                    std::string _param = _curToken.second;
                    if(_curToken.first == Parser::VARIABLE){
                        _param = Parser::GetVariableValue(_curToken.second);
                    }
                    if(_curToken.first == Parser::HARDSTRING){
                    _param = _param.substr(1,_curToken.second.size()-2);
                    }

        std::string _blockName = _curBlock[_tokenIndex+2].second;
       
        EventManagement::FileEventTrigger _trigger = EventManagement::FileEventTrigger(_blockName,_param);
        EventManagement::_manager.AddEventTrigger(_trigger);
        _tokenIndex+=2;
}
void Commands::SetTimeOut(int& _tokenIndex, std::vector<std::pair<Parser::TokenPrimaryType, std::string> >& _curBlock){
     
     std::pair<Parser::TokenPrimaryType, std::string> _curToken = _curBlock[_tokenIndex+1];
                    std::string _param = _curToken.second;
                    if(_curToken.first == Parser::VARIABLE){
                        _param = Parser::GetVariableValue(_curToken.second);
                    }
                    if(_curToken.first == Parser::HARDSTRING){
                    _param = _param.substr(1,_curToken.second.size()-2);
                    }

        std::string _blockName = _curBlock[_tokenIndex+2].second; 
        Utility::Timer _timer = Utility::Timer();
        int _timeToWait = Utility::StringToInt(_param);
        _timer.SetTimeout(_timeToWait,_blockName);
        _tokenIndex+=2;
}

void Commands::SetInterval(int& _tokenIndex, std::vector<std::pair<Parser::TokenPrimaryType, std::string> >& _curBlock){
     
     std::pair<Parser::TokenPrimaryType, std::string> _curToken = _curBlock[_tokenIndex+1];
                    std::string _param = _curToken.second;
                    if(_curToken.first == Parser::VARIABLE){
                        _param = Parser::GetVariableValue(_curToken.second);
                    }
                    if(_curToken.first == Parser::HARDSTRING){
                    _param = _param.substr(1,_curToken.second.size()-2);
                    }

        std::string _blockName = _curBlock[_tokenIndex+2].second; 
        Utility::Timer _timer = Utility::Timer();
        int _timeToWait = Utility::StringToInt(_param);
        _timer.SetInterval(_timeToWait,_blockName);
        _tokenIndex+=2;
}



void Operators::_declareVar(std::string& _varName, std::string& _varType){
    
    //just declare
    //*TO DO : Exeption Handling
    Parser::VariableType _newVarType = Parser::_variablesNameDeclare[_varType];
    std::pair<std::string,std::pair<Parser::VariableType,std::string>> _newVar = std::make_pair(_varName,
                                std::make_pair(_newVarType,""));
    Parser::_variables.push_back(_newVar);
}
void Operators::_assignValueToVar(std::string& _varName, std::string& _varValue){
    for(auto& _var : Parser::_variables){
        if(_var.first == _varName){
            if(_var.second.first == Parser::STRING){
                _varValue = _varValue.substr(1,_varValue.size()-2);
            }
            _var.second.second = _varValue;
            return;
        }
    }
}

