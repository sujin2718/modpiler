#ifndef _MODPILER_MNODE_H_
#define _MODPILER_MNODE_H_

#include <memory>
#include <vector>

#include "mod_define.h"
#include "mod_elem.h"
#include "mod_op.h"

namespace modpiler {

class MNode : public MElem {
   private:
    std::vector<s_ptr<MNode>> parents;
    std::vector<s_ptr<MNode>> children;

    s_ptr<MOp> op;
   public:
    const std::vector<s_ptr<MNode>>& GetParents();
    const std::vector<s_ptr<MNode>>& GetChilderen();
    void AddParent(s_ptr<MNode> parent);
    // add child and output as child's input
    void AddChildren(s_ptr<MNode> child);

    MNode(const std::string& name) : MElem(name) {}
    void Execute();
};

};  // namespace modpiler

#endif