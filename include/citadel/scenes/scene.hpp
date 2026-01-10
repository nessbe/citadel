// File:       scene.hpp
// Project:    citadel
// Repository: https://github.com/nessbe/citadel
//
// Copyright (c) 2025-2026 nessbe
// This file is part of the citadel project and is licensed
// under the terms specified in the LICENSE file located at the
// root of this repository.
//
// Unless required by applicable law or agreed to in writing,
// the software is distributed on an "AS IS" BASIS, WITHOUT
// WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the LICENSE file for details.

#pragma once

#include <vector>

#include "citadel/attributes.hpp"
#include "citadel/export.hpp"

#include "citadel/math/matrices/mat4.hpp"

#include "citadel/memory/reference.hpp"

#include "citadel/rendering/cameras/camera.hpp"

#include "citadel/rendering/meshes/mesh_instance.hpp"

namespace citadel {
	class CITADEL_API scene {
	public:
		struct data {
			mat4 view;
			mat4 projection;
		};

	public:
		scene(const reference<camera>& camera);

		void refresh();

		CITADEL_NODISCARD const mat4& view() const noexcept;
		CITADEL_NODISCARD const mat4& projection() const noexcept;
		CITADEL_NODISCARD mat4 view_projection() const noexcept;

		void add(const mesh_instance& mesh);
		CITADEL_NODISCARD const std::vector<mesh_instance>& meshes() const noexcept;

		CITADEL_NODISCARD camera& camera() const noexcept;
		CITADEL_NODISCARD data pack() const;

	private:
		mat4 projection_;
		mat4 view_;

		std::vector<mesh_instance> meshes_;

		reference<class camera> camera_;
	};
}
