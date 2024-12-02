// This file is modified from the base code automatically generated by the CUTLASS 3.2.1 Python 
// interface (https://github.com/nvidia/cutlass/python)

#include <torch/extension.h>
#include <ATen/ATen.h>
#include <pybind11/stl.h>

// ------ For Linear ------
// CUDA forward declarations
at::Tensor batched_gemm_kernel(const at::Tensor& A, const at::Tensor& B, at::optional<const at::Tensor> C=at::nullopt, int alpha=1, int beta=0);

// C++ interface
at::Tensor batched_gemm(const at::Tensor& A, const at::Tensor& B, at::optional<const at::Tensor> C=at::nullopt, int alpha=1, int beta=0) {
  return batched_gemm_kernel(A, B, C, alpha, beta);
}

// CUDA forward declarations
at::Tensor conv_int8_kernel(
    const at::Tensor& A, const at::Tensor& B, at::optional<const at::Tensor> C=at::nullopt,
    std::tuple<int, int> stride={1, 1}, std::tuple<int, int> padding={0, 0}, std::tuple<int, int> dilation={1, 1},
    float alpha=1.f, float beta=0.f,
    std::string split_k_mode="serial", int split_k_slices=1, bool output_nchw_chlast=true);

// C++ interface
at::Tensor conv_int8(
    const at::Tensor& A, const at::Tensor& B, at::optional<const at::Tensor> C=at::nullopt,
    std::tuple<int, int> stride={1, 1}, std::tuple<int, int> padding={0, 0}, std::tuple<int, int> dilation={1, 1},
    float alpha=1.f, float beta=0.f,
    std::string split_k_mode="serial", int split_k_slices=1, bool output_nchw_chlast=true){
    return conv_int8_kernel(A, B, C, stride, padding, dilation, alpha, beta, split_k_mode, split_k_slices, output_nchw_chlast);
}

PYBIND11_MODULE(TORCH_EXTENSION_NAME, m) {
  m.def("run",      py::overload_cast<const at::Tensor&, const at::Tensor&, at::optional<const at::Tensor>, int, int>(&batched_gemm), py::arg("A"), py::arg("B"), py::arg("C") = nullptr, py::arg("alpha") = 1, py::arg("beta") = 0);
  m.def("run_conv2d", py::overload_cast<const at::Tensor&, const at::Tensor&, at::optional<const at::Tensor>,
    std::tuple<int, int>, std::tuple<int, int>, std::tuple<int, int>, float, float,  std::string, int, bool>(
        &conv_int8), py::arg("A"), py::arg("B"), py::arg("C") = nullptr,
        py::arg("stride") = std::make_tuple(1, 1), py::arg("padding") = std::make_tuple(1, 1), py::arg("dilation") = std::make_tuple(1, 1),
        py::arg("alpha") = 1.f, py::arg("beta") = 0.f,
        py::arg("split_k_mode") = "serial", py::arg("split_k_slices") = 1,
        py::arg("output_nchw_chlast")=true);
}