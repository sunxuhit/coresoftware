#ifndef __NEEDLE__
#define __NEEDLE__


namespace SeamStress
{
  class Needle
  {
    public:
      Needle(){}
      ~Needle(){}
      
      virtual void operator()(void *thread)
      {
        (*func)(thread);
      }
      
      void (*func)(void*);
  };
}

#endif
