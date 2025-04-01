#ifndef _MODPILER_MNODE_H_
#define _MODPILER_MNODE_H_

#include <memory>
#include <vector>

#include "mod_define.h"
#include "mod_elem.h"

namespace modpiler {

class MNode : public MElem {
   protected:
    std::vector<s_ptr<MNode>> parents;
    std::vector<s_ptr<MNode>> children;

   public:
    const std::vector<s_ptr<MNode>>& GetParents();
    const std::vector<s_ptr<MNode>>& GetChilderen();
    void AddParent(s_ptr<MNode> parent);
    // add child and output as child's input
    void AddChildren(s_ptr<MNode> child);

    MNode(const std::string& name) : MElem(name) {}
    // execute?? 
    virtual void Execute() = 0;
    // visitor pattern
    virtual void Visit() = 0;
};

};  // namespace modpiler

#endif