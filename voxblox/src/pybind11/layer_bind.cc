#include "voxblox/core/layer.h"

#include <pybind11/pybind11.h>
namespace py = pybind11;

using voxblox::TsdfVoxel;
using voxblox::EsdfVoxel;
using voxblox::LayerProto;

using TsdfLayer = voxblox::Layer<TsdfVoxel>;
using EsdfLayer = voxblox::Layer<EsdfVoxel>;

void layer_bind(py::module &m) {
  /* TODO(mereweth@jpl.nasa.gov) - use shared_ptr instead of default unique_ptr
   * for Python reference counting?
   */
    py::class_<TsdfLayer> (m, "TsdfLayer")
    //py::class_<TsdfLayer, std::shared_ptr<TsdfLayer> >(m, "TsdfLayer")
        .def(py::init<const LayerProto&>())

        .def_property_readonly("block_size", &TsdfLayer::block_size)
        .def_property_readonly("voxel_size", &TsdfLayer::voxel_size)
        .def_property_readonly("voxels_per_side", &TsdfLayer::voxels_per_side)

        // TODO(mereweth@jpl.nasa.gov) - can cause segfault
        //.def("saveToFile", &TsdfLayer::saveToFile)

        ;

    py::class_<EsdfLayer>(m, "EsdfLayer")
    //py::class_<EsdfLayer, std::shared_ptr<EsdfLayer> >(m, "EsdfLayer")
        .def(py::init<const LayerProto&>())

        .def_property_readonly("block_size", &EsdfLayer::block_size)
        .def_property_readonly("voxel_size", &EsdfLayer::voxel_size)
        .def_property_readonly("voxels_per_side", &EsdfLayer::voxels_per_side)

        // TODO(mereweth@jpl.nasa.gov) - can cause segfault
        //.def("saveToFile", &EsdfLayer::saveToFile)

        ;
}
