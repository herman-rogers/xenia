/**
 ******************************************************************************
 * Xenia : Xbox 360 Emulator Research Project                                 *
 ******************************************************************************
 * Copyright 2015 Ben Vanik. All rights reserved.                             *
 * Released under the BSD license - see LICENSE in the root for more details. *
 ******************************************************************************
 */

#include "xenia/debug/ui/model/module.h"

#include "xenia/debug/ui/model/system.h"

namespace xe {
namespace debug {
namespace ui {
namespace model {

void Module::Update(const proto::ModuleListEntry* entry) {
  std::memcpy(&entry_, entry, sizeof(entry_));
}

}  // namespace model
}  // namespace ui
}  // namespace debug
}  // namespace xe
