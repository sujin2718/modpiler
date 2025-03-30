#ifndef _MODPILER_OP_H_
#define _MODPILER_OP_H_

namespace modpiler {

class MOp {

   public:  
    virtual void Run() = 0;
};

class MAddOp : public MOp{
    public:
    void Run();
};

};  // namespace modpiler

#endif