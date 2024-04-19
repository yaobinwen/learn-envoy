#pragma once

#include "envoy/extensions/http/header_formatters/preserve_case/v3/preserve_case.pb.h"
#include "envoy/http/header_formatter.h"

#include "source/common/common/utility.h"

namespace Envoy {
namespace Extensions {
namespace Http {
namespace HeaderFormatters {
namespace PreserveCase {

class PreserveCaseHeaderFormatter : public Envoy::Http::StatefulHeaderKeyFormatter {
public:
  // Envoy::Http::StatefulHeaderKeyFormatter
  PreserveCaseHeaderFormatter(const bool forward_reason_phrase);

  std::string format(absl::string_view key) const override;
  void processKey(absl::string_view key) override;
  void setReasonPhrase(absl::string_view reason_phrase) override;
  absl::string_view getReasonPhrase() const override;

private:
  StringUtil::CaseUnorderedSet original_header_keys_;
  bool forward_reason_phrase_{false};
  std::string reason_phrase_;
};

} // namespace PreserveCase
} // namespace HeaderFormatters
} // namespace Http
} // namespace Extensions
} // namespace Envoy
