/* Copyright 2020 The TensorFlow Authors. All Rights Reserved.

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
==============================================================================*/

#ifndef TENSORFLOW_COMPILER_MLIR_TENSORFLOW_IR_TF_OP_INTERFACES_H_
#define TENSORFLOW_COMPILER_MLIR_TENSORFLOW_IR_TF_OP_INTERFACES_H_
#include "mlir/IR/OpImplementation.h"  // from @llvm-project
#include "tensorflow/compiler/mlir/tensorflow/ir/tf_structs.h"
#include "tensorflow/compiler/mlir/tensorflow/ir/tf_verifiers.h"

namespace mlir {
namespace TF {

//===----------------------------------------------------------------------===//
// TensorFlow Contraction Fusion.
//===----------------------------------------------------------------------===//

struct ContractionFusion {
  ContractionFusion(StringRef output_kernel, ArrayRef<int> additional_arguments)
      : output_kernel(output_kernel.str()),
        additional_arguments(additional_arguments.begin(),
                             additional_arguments.end()) {}

  // Name of the output kernel implementing the contraction fusion.
  std::string output_kernel;

  // Indices of additional arguments that will be forwarded to the fused
  // operation (e.g. forward bias vector if fusing BiasAdd operation).
  SmallVector<int, 4> additional_arguments;
};

#include "tensorflow/compiler/mlir/tensorflow/ir/tf_op_interfaces.h.inc"
}  // namespace TF
}  // namespace mlir

#endif  // TENSORFLOW_COMPILER_MLIR_TENSORFLOW_IR_TF_OP_INTERFACES_H_
