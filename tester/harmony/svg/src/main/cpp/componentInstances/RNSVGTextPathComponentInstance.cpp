#include "RNSVGTextPathComponentInstance.h"
#include "Props.h"
#include <react/renderer/core/ConcreteState.h>
#include <sstream>
#include "SvgTSpan.h"

namespace rnoh {

RNSVGTextPathComponentInstance::RNSVGTextPathComponentInstance(Context context) : CppComponentInstance(std::move(context)) {
    SetSvgNode(m_svgTP);
}

void RNSVGTextPathComponentInstance::onPropsChanged(SharedConcreteProps const &props) {
    CppComponentInstance::onPropsChanged(props);
    // TODO: move ArkUINode to base class and use template function
    if (!props->responsible) {
        m_svgArkUINode.setHitTestMode(facebook::react::PointerEventsMode::None);
    } else {
        m_svgArkUINode.setHitTestMode(facebook::react::PointerEventsMode::Auto);
    }
    GetSvgNode()->UpdateCommonProps(props);

    m_svgTP->UpdateFontProps(props);
    m_svgTP->UpdateTextProps(props);
    m_svgTP->href_ = props->href;
    m_svgTP->startOffset_ = StringUtils::FromString(props->startOffset).ConvertToPx();
    m_svgTP->spacing_ = textPathSpacingFromStr(props->spacing);
    m_svgTP->midLine_ = textPathMidLineFromStr(props->midLine);
    m_svgTP->side_ = textPathSideFromStr(props->side);
    m_svgTP->method_ = textPathMethodFromStr(props->method);
}

    void RNSVGTextPathComponentInstance::onChildInserted(ComponentInstance::Shared const &childComponentInstance, std::size_t index) {
        auto child = std::dynamic_pointer_cast<SvgHost>(childComponentInstance);
        if (!child) {
            return;
        }
        OnChildInsertCommon(child);
        LOG(INFO) << "TEXT_PATH insert child";
    }
} // namespace rnoh
