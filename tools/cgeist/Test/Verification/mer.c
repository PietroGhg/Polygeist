// RUN: cgeist %s --function=kernel_deriche -S | FileCheck %s
// RUN: cgeist %s --function=kernel_deriche -S -memref-fullrank | FileCheck %s --check-prefix=FULLRANK

int kernel_deriche(int a[30]) {
    a[0]++;
    return a[1];
}

// CHECK:  func @kernel_deriche(%arg0: memref<?xi32>) -> i32
// CHECK-NEXT:    %c1_i32 = arith.constant 1 : i32
// CHECK-NEXT:    %0 = affine.load %arg0[0] : memref<?xi32>
// CHECK-NEXT:    %1 = arith.addi %0, %c1_i32 : i32
// CHECK-NEXT:    affine.store %1, %arg0[0] : memref<?xi32>
// CHECK-NEXT:    %2 = affine.load %arg0[1] : memref<?xi32>
// CHECK-NEXT:    return %2 : i32
// CHECK-NEXT:  }

// FULLRANK:  func @kernel_deriche(%arg0: memref<30xi32>) -> i32
