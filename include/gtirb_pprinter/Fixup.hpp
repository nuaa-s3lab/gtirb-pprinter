#ifndef GT_PPRINTER_FIXUP_H
#define GT_PPRINTER_FIXUP_H
#include "Export.hpp"

namespace gtirb {
class Context;
class Module;
} // namespace gtirb

namespace gtirb_pprint {
class PrettyPrinter;

void DEBLOAT_PRETTYPRINTER_EXPORT_API applyFixups(gtirb::Context& Ctx,
                                                  gtirb::Module& Mod,
                                                  const PrettyPrinter& Printer);

/// fixes up any direct references to global symbols, which
/// are illegal relocations in shared objects.
void fixupSharedObject(gtirb::Context& Ctx, gtirb::Module& Mod);

/// fixup to ensure that PE entry symbols are correctly named
void fixupPESymbols(gtirb::Context& Ctx, gtirb::Module& Mod);

} // namespace gtirb_pprint

#endif
