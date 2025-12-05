// File:       citadel.hpp
// Project:    citadel
// Repository: https://github.com/nessbe/citadel
//
// Copyright (c) 2025 nessbe
// This file is part of the citadel project and is licensed
// under the terms specified in the LICENSE file located at the
// root of this repository.
//
// Unless required by applicable law or agreed to in writing,
// the software is distributed on an "AS IS" BASIS, WITHOUT
// WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the LICENSE file for details.

#pragma once

#include "citadel/architectures.hpp"
#include "citadel/assert.hpp"
#include "citadel/attributes.hpp"
#include "citadel/compilers.hpp"
#include "citadel/exceptions.hpp"
#include "citadel/export.hpp"
#include "citadel/packing.hpp"
#include "citadel/platforms.hpp"
#include "citadel/pointers.hpp"
#include "citadel/pragma.hpp"
#include "citadel/utility.hpp"
#include "citadel/warnings.hpp"

#include "citadel/core/application.hpp"
#include "citadel/core/engine.hpp"
#include "citadel/core/entry_point.hpp"
#include "citadel/core/exit_code.hpp"

#include "citadel/core/display/surface.hpp"
#include "citadel/core/display/window.hpp"

#include "citadel/core/extensions/extension_loader.hpp"

#include "citadel/core/layers/layer.hpp"
#include "citadel/core/layers/layer_stack.hpp"

#include "citadel/debug/exceptions/assertion_error.hpp"

#include "citadel/drivers/opengl.hpp"
#include "citadel/drivers/opengl/opengl_context.hpp"
#include "citadel/drivers/opengl/opengl_index_buffer.hpp"
#include "citadel/drivers/opengl/opengl_loader.hpp"
#include "citadel/drivers/opengl/opengl_rendering_api.hpp"
#include "citadel/drivers/opengl/opengl_shader.hpp"
#include "citadel/drivers/opengl/opengl_shader_program.hpp"
#include "citadel/drivers/opengl/opengl_surface.hpp"
#include "citadel/drivers/opengl/opengl_texture_2d.hpp"
#include "citadel/drivers/opengl/opengl_vertex_array.hpp"
#include "citadel/drivers/opengl/opengl_vertex_buffer.hpp"

#include "citadel/formats/obj/obj_face.hpp"
#include "citadel/formats/obj/obj_vertex.hpp"

#include "citadel/formats/tga/tga_header.hpp"
#include "citadel/formats/tga/tga_reader.hpp"

#include "citadel/io/reader.hpp"
#include "citadel/io/stream.hpp"
#include "citadel/io/stream_direction.hpp"
#include "citadel/io/writer.hpp"

#include "citadel/io/binary/binary_reader.hpp"
#include "citadel/io/binary/binary_writer.hpp"

#include "citadel/io/filesystem/file.hpp"
#include "citadel/io/filesystem/file_open_mode.hpp"

#include "citadel/io/resources/meshes/mesh_reader.hpp"

#include "citadel/io/resources/images/image_reader.hpp"

#include "citadel/io/text/text_reader.hpp"
#include "citadel/io/text/text_writer.hpp"

#include "citadel/math/angles.hpp"
#include "citadel/math/epsilon.hpp"

#include "citadel/math/matrices/mat3.hpp"
#include "citadel/math/matrices/mat4.hpp"

#include "citadel/math/transforms/transform_3d.hpp"

#include "citadel/math/vectors/vec2.hpp"
#include "citadel/math/vectors/vec3.hpp"
#include "citadel/math/vectors/vec4.hpp"

#include "citadel/memory/reference.hpp"
#include "citadel/memory/scope.hpp"

#include "citadel/platforms/stl/stl_file.hpp"

#include "citadel/platforms/windows.hpp"
#include "citadel/platforms/windows/wgl_loader.hpp"
#include "citadel/platforms/windows/windows_window.hpp"

#include "citadel/rendering/color.hpp"
#include "citadel/rendering/render_command.hpp"
#include "citadel/rendering/rendering_api.hpp"
#include "citadel/rendering/rendering_api_type.hpp"
#include "citadel/rendering/rendering_context.hpp"

#include "citadel/rendering/cameras/camera.hpp"
#include "citadel/rendering/cameras/orthographic_camera.hpp"
#include "citadel/rendering/cameras/perspective_camera.hpp"

#include "citadel/rendering/indices/index.hpp"
#include "citadel/rendering/indices/index_buffer.hpp"

#include "citadel/rendering/materials/material.hpp"

#include "citadel/rendering/meshes/mesh.hpp"
#include "citadel/rendering/meshes/mesh_instance.hpp"

#include "citadel/rendering/shaders/shader.hpp"
#include "citadel/rendering/shaders/shader_data_type.hpp"
#include "citadel/rendering/shaders/shader_program.hpp"
#include "citadel/rendering/shaders/shader_type.hpp"
#include "citadel/rendering/shaders/uniform_info.hpp"

#include "citadel/rendering/textures/image.hpp"
#include "citadel/rendering/textures/texture.hpp"
#include "citadel/rendering/textures/texture_2d.hpp"

#include "citadel/rendering/vertices/vertex.hpp"
#include "citadel/rendering/vertices/vertex_array.hpp"
#include "citadel/rendering/vertices/vertex_buffer.hpp"
#include "citadel/rendering/vertices/vertex_buffer_element.hpp"
#include "citadel/rendering/vertices/vertex_buffer_layout.hpp"

#include "citadel/utils/string/string_convertion.hpp"
