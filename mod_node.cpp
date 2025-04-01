#include "mod_node.h"

namespace modpiler {

const std::vector<s_ptr<MNode>>& MNode::GetParents() { return this->parents; }
const std::vector<s_ptr<MNode>>& MNode::GetChilderen() {
    return this->children;
}

void MNode::AddParent(s_ptr<MNode> parent) { this->parents.push_back(parent); }
// todo: child -> input is this node's output. 
void MNode::AddChildren(s_ptr<MNode> child) { this->children.push_back(child); }

void MNode::Execute() { ;}

};  // namespace modpiler
