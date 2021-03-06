// ------------------------------------------------------------
// Copyright (c) Microsoft Corporation.  All rights reserved.
// Licensed under the MIT License (MIT). See License.txt in the repo root for license information.
// ------------------------------------------------------------

#pragma once

namespace Hosting2
{
    class ContainerInfoReply : public Serialization::FabricSerializable
    {
    public:
        ContainerInfoReply();
        ContainerInfoReply(
            Common::ErrorCode const & error,
            std::wstring const & containerInfo);

        __declspec(property(get = get_Error)) Common::ErrorCode const & Error;
        Common::ErrorCode const & get_Error() const { return error_; }

        __declspec(property(get=get_ContainerInfo)) std::wstring const & ContainerInfo;
        std::wstring const & get_ContainerInfo() const { return containerInfo_; }


        void WriteTo(Common::TextWriter & w, Common::FormatOptions const &) const;

        FABRIC_FIELDS_02(error_, containerInfo_);

    private:
        Common::ErrorCode error_;
        std::wstring containerInfo_;
    };
}
