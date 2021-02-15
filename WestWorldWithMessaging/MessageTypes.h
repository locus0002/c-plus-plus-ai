#ifndef MESSAGE_TYPES
#define MESSAGE_TYPES

#include <string>

enum message_type
{
  Msg_HiHoneyImHome,
  Msg_StewReady,
  Msg_Insult,
  Msg_ReplyInsult,
  Msg_FinishFight,
  Msg_Surrendering
};


inline std::string MsgToStr(int msg)
{
  switch (msg)
  {
  case 0:
    
    return "HiHoneyImHome"; 

  case 1:
    
    return "StewReady";
  
  //--------------------------------------------
  //  Vladimir Aca
  //  New messages were implemented to identify
  //  the transitions between barfly states.
  //--------------------------------------------
  case 2:

    return "You are a huge m0@#$ f@#$@ !!!!!";

  case 3:

    return "I am not afraid of you!";

  case 4:

    return "The Fight finished";

  case 5:

    return "Barfly surrendered... Miner win!!";
  //--------------------------------------------
  default:

    return "Not recognized!";
  }
}

#endif