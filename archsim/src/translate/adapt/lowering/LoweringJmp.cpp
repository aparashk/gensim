/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "translate/adapt/BlockJITAdaptorLowering.h"
#include "translate/adapt/BlockJITAdaptorLoweringContext.h"

using namespace archsim::translate::adapt;

bool BlockJITJMPLowering::Lower(const captive::shared::IRInstruction*& insn) {
	
	const auto &target = insn->operands[0];
	assert(target.is_block());
	
	GetBuilder().CreateBr(GetContext().GetLLVMBlock(target.value));
	
	insn++;
	
	return true;
}
