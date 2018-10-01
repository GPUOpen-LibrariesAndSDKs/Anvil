//
// Copyright (c) 2018 Advanced Micro Devices, Inc. All rights reserved.
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
#include "misc/semaphore_create_info.h"

Anvil::SemaphoreCreateInfoUniquePtr Anvil::SemaphoreCreateInfo::create(const Anvil::BaseDevice* in_device_ptr)
{
    Anvil::SemaphoreCreateInfoUniquePtr result_ptr(nullptr,
                                                   std::default_delete<Anvil::SemaphoreCreateInfo>() );

    result_ptr.reset(
        new Anvil::SemaphoreCreateInfo(in_device_ptr,
                                       Anvil::MTSafety::INHERIT_FROM_PARENT_DEVICE)
    );

    return result_ptr;
}

Anvil::SemaphoreCreateInfo::SemaphoreCreateInfo(const Anvil::BaseDevice* in_device_ptr,
                                                MTSafety                 in_mt_safety)
    :m_device_ptr                                             (in_device_ptr),
     m_exportable_external_semaphore_handle_types             (Anvil::ExternalSemaphoreHandleTypeFlagBits::NONE),
#if defined(_WIN32)
     m_exportable_nt_handle_info_specified                    (false),
     m_exportable_nt_handle_info_security_attributes_specified(false),
#endif
     m_mt_safety                                              (in_mt_safety)
{
    /* Stub */
}