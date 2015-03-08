#pragma once
#include <vector>
#include <memory>
#include "backend/backend_chunk.h"
#include "common/scale.h"
#include "common/common.h"

namespace minerva {

class ComputeFn;

class Backend {
 public:
  Backend() = default;
  DISALLOW_COPY_AND_ASSIGN(Backend);
  virtual ~Backend() = default;
  virtual std::vector<BackendChunk*> Create(const std::vector<BackendChunk*>& params, const std::vector<Scale>& result_sizes, ComputeFn* fn) = 0;
  virtual BackendChunk* CreateOne(BackendChunk*, const Scale&, ComputeFn*);
  virtual void Wait(BackendChunk*) = 0;
  virtual void WaitForAll() = 0;
  virtual std::shared_ptr<float> GetValue(BackendChunk*) = 0;
};

}  // namespace minerva
