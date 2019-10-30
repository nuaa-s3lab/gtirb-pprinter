//===- PePrettyPrinter.hpp --------------------------------------*- C++ -*-===//
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
#ifndef GTIRB_PP_PE_PRINTER_H
#define GTIRB_PP_PE_PRINTER_H

#include "PrettyPrinter.hpp"

namespace gtirb_pprint {

enum SECTION_CHARACTERISTICS {
  IMAGE_SCN_CNT_CODE = 0x00000020,
  IMAGE_SCN_CNT_INITIALIZED_DATA = 0x00000040,
  IMAGE_SCN_CNT_UNINITIALIZED_DATA = 0x00000080,
  IMAGE_SCN_MEM_DISCARDABLE = 0x02000000,
  IMAGE_SCN_MEM_NOT_CACHED = 0x04000000,
  IMAGE_SCN_MEM_NOT_PAGED = 0x08000000,
  IMAGE_SCN_MEM_SHARED = 0x10000000,
  IMAGE_SCN_MEM_EXECUTE = 0x20000000,
  IMAGE_SCN_MEM_READ = 0x40000000,
  IMAGE_SCN_MEM_WRITE = 0x80000000,
};

class PePrettyPrinter : public PrettyPrinterBase {
public:
  PePrettyPrinter(gtirb::Context& context, gtirb::IR& ir, const Syntax& syntax,
                  const PrintingPolicy& policy);

  static const PrintingPolicy& defaultPrintingPolicy();

protected:
  bool skipEA(const gtirb::Addr x) const override;
  bool isInSkippedDataDirectory(const gtirb::Addr x) const;

private:
  // TODO: Add to policy?
  // Names of data directories that should be output.
  std::unordered_set<std::string> keepDataDirectories = {};
  std::vector<std::tuple<std::string, uint64_t, uint64_t>> dataDirectories;
};

} // namespace gtirb_pprint

#endif /* GTIRB_PP_PE_PRINTER_H */
