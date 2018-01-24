//
// Copyright (c) 2017 Advanced Micro Devices, Inc. All rights reserved.
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.
//

#ifndef ANVIL_COMPUTE_PIPELINE_INFO_H
#define ANVIL_COMPUTE_PIPELINE_INFO_H

#include "misc/base_pipeline_info.h"


namespace Anvil
{
    class ComputePipelineInfo : public BasePipelineInfo
    {
    public:
        /* Public functions */
        static std::unique_ptr<Anvil::ComputePipelineInfo> create_derivative_pipeline_info(bool                               in_disable_optimizations,
                                                                                           bool                               in_allow_derivatives,
                                                                                           const ShaderModuleStageEntryPoint& in_compute_shader_stage_entrypoint_info,
                                                                                           Anvil::PipelineID                  in_base_pipeline_id);
        static std::unique_ptr<Anvil::ComputePipelineInfo> create_proxy_pipeline_info     ();
        static std::unique_ptr<Anvil::ComputePipelineInfo> create_regular_pipeline_info   (bool                               in_disable_optimizations,
                                                                                           bool                               in_allow_derivatives,
                                                                                           const ShaderModuleStageEntryPoint& in_compute_shader_stage_entrypoint_info);

        /** Adds a new specialization constant.
         *
         *  @param in_constant_id  ID of the specialization constant to assign data for.
         *  @param in_n_data_bytes Number of bytes under @param in_data_ptr to assign to the specialization constant.
         *  @param in_data_ptr     A buffer holding the data to be assigned to the constant. Must hold at least
         *                         @param in_n_data_bytes bytes that will be read by the function.
         *
         *  @return true if successful, false otherwise.
         **/
        bool add_specialization_constant(uint32_t    in_constant_id,
                                         uint32_t    in_n_data_bytes,
                                         const void* in_data_ptr)
        {
            return BasePipelineInfo::add_specialization_constant(Anvil::SHADER_STAGE_COMPUTE,
                                                                 in_constant_id,
                                                                 in_n_data_bytes,
                                                                 in_data_ptr);
        }

        ~ComputePipelineInfo();

    private:
        ComputePipelineInfo();
    };
};

#endif /* ANVIL_COMPUTE_PIPELINE_INFO_H */
