/**
 ******************************************************************************
 * Xenia : Xbox 360 Emulator Research Project                                 *
 ******************************************************************************
 * Copyright 2013 Ben Vanik. All rights reserved.                             *
 * Released under the BSD license - see LICENSE in the root for more details. *
 ******************************************************************************
 */

#ifndef XENIA_VFS_DEVICES_DISC_IMAGE_ENTRY_H_
#define XENIA_VFS_DEVICES_DISC_IMAGE_ENTRY_H_

#include <string>
#include <vector>

#include "xenia/base/filesystem.h"
#include "xenia/base/mapped_memory.h"
#include "xenia/vfs/entry.h"

namespace xe {
namespace vfs {

class DiscImageDevice;

class DiscImageEntry : public Entry {
 public:
  DiscImageEntry(Device* device, Entry* parent, std::string path,
                 MappedMemory* mmap);
  ~DiscImageEntry() override;

  MappedMemory* mmap() const { return mmap_; }
  size_t data_offset() const { return data_offset_; }
  size_t data_size() const { return data_size_; }

  X_STATUS Open(kernel::KernelState* kernel_state, uint32_t desired_access,
                kernel::object_ref<kernel::XFile>* out_file) override;

  bool can_map() const override { return true; }
  std::unique_ptr<MappedMemory> OpenMapped(MappedMemory::Mode mode,
                                           size_t offset,
                                           size_t length) override;

 private:
  friend class DiscImageDevice;

  MappedMemory* mmap_;
  size_t data_offset_;
  size_t data_size_;
};

}  // namespace vfs
}  // namespace xe

#endif  // XENIA_VFS_DEVICES_DISC_IMAGE_ENTRY_H_
