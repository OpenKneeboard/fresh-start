// Copyright 2025 Fred Emmott <fred@fredemmott.com>
// SPDX-License-Identifier: MIT
#pragma once

#include <Windows.h>
#include <wil/registry.h>

#include "Artifact.hpp"

class HKCULayer final : public Artifact {
 public:
  HKCULayer();
  ~HKCULayer() override = default;
  [[nodiscard]] bool IsPresent() const override;
  void Remove() override;
  [[nodiscard]] std::string_view GetTitle() const override;
  void DrawCardContent() const override;
  [[nodiscard]] Kind GetKind() const override;
  [[nodiscard]] Version GetEarliestVersion() const override;
  [[nodiscard]] std::optional<Version> GetRemovedVersion() const override;

 private:
  wil::unique_hkey mKey;
  struct Value {
    std::wstring mValueName;
    std::string mLabel;
  };
  std::vector<Value> mValues;
};