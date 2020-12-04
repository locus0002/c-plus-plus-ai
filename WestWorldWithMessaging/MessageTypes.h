#ifndef MESSAGE_TYPES
#define MESSAGE_TYPES

#include <string>

enum message_type
{
  Msg_HiHoneyImHome,
  Msg_StewReady,
  Msg_Insult,
  Msg_ReplyInsult,
  Msg_FinishFight
};


inline std::string MsgToStr(int msg)
{
  switch (msg)
  {
  case 1:
    
    return "HiHoneyImHome"; 

  case 2:
    
    return "StewReady";
  
  case 3:

    return "You are a huge m0@#$ f@#$@ !!!!!";

  case 4:

    return "I am not afraid of you!";

  case 5:

    return "The Fight finished";

  default:

    return "Not recognized!";
  }
}

#endif