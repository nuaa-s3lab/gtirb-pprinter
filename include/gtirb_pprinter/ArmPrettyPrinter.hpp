//===- ArmPrettyPrinter.h -------------------------------------*- C++ -*-===//
//
//  Copyright (C) 2019 GrammaTech, Inc.
//
//  This code is licensed under the MIT license. See the LICENSE file in the
//  project root for license terms.
//
//  This project is sponsored by the Office of Naval Research, One Liberty
//  Center, 875 N. Randolph Street, Arlington, VA 22203 under contract #
//  N68335-17-C-0700.  The content of the information does not necessarily
//  reflect the position or policy of the Government and no official
//  endorsement should be inferred.
//
//===----------------------------------------------------------------------===//
#ifndef GTIRB_PP_ARM_PRINTER_H
#define GTIRB_PP_ARM_PRINTER_H

#include "ElfPrettyPrinter.hpp"

namespace gtirb_pprint {

class ArmSyntax : public ElfSyntax {};

class ArmPrettyPrinter : public ElfPrettyPrinter {
public:
  ArmPrettyPrinter(gtirb::Context& context, gtirb::Module& module,
                   const ArmSyntax& syntax, const PrintingPolicy& policy);

protected:
  const ArmSyntax& armSyntax;

  std::string getRegisterName(unsigned int reg) const override;
  void printHeader(std::ostream& os) override;
  void printFunctionHeader(std::ostream& os, gtirb::Addr addr) override;
  void printSectionHeader(std::ostream& os, const gtirb::Addr addr) override;
  void printDecodeMode(std::ostream& os, const gtirb::Block& x) override;
  void fixupInstruction(cs_insn& inst) override;
  void printInstruction(std::ostream& os, const cs_insn& inst,
                        const gtirb::Offset& offset) override;

  void printOperandList(std::ostream& os, const cs_insn& inst) override;
  void printOperand(std::ostream& os, const cs_insn& inst,
                    uint64_t index) override;
  void printOpRegdirect(std::ostream& os, const cs_insn& inst,
                        uint64_t index) override;
  void printOpImmediate(std::ostream& os,
                        const gtirb::SymbolicExpression* symbolic,
                        const cs_insn& inst, uint64_t index) override;
  void printOpIndirect(std::ostream& os,
                       const gtirb::SymbolicExpression* symbolic,
                       const cs_insn& inst, uint64_t index) override;

  std::string getFunctionName(gtirb::Addr x) const override;

private:
  static volatile bool registered;
};

class ArmPrettyPrinterFactory : public PrettyPrinterFactory {
public:
  const PrintingPolicy& defaultPrintingPolicy() const override;
  std::unique_ptr<PrettyPrinterBase>
  create(gtirb::Context& context, gtirb::Module& module,
         const PrintingPolicy& policy) override;
};

} // namespace gtirb_pprint

#endif /* GTIRB_PP_ARM_PRINTER_H */
