#include "RNSVGPatternComponentInstance.h"
#include "Props.h"
#include <react/renderer/core/ConcreteState.h>
#include <sstream>
#include "utils/StringUtils.h"

namespace rnoh {

RNSVGPatternComponentInstance::RNSVGPatternComponentInstance(Context context)
    : CppComponentInstance(std::move(context)) {
    LOG(INFO) << "[RNSVGPatternComponentInstance] init";
    SetSvgNode(std::make_shared<SvgPattern>());
}

void RNSVGPatternComponentInstance::onPropsChanged(SharedConcreteProps const &props) {
    CppComponentInstance::onPropsChanged(props);
    // TODO: move ArkUINode to base class and use template function
    if (!props->responsible) {
        m_svgArkUINode.setHitTestMode(facebook::react::PointerEventsMode::None);
    } else {
        m_svgArkUINode.setHitTestMode(facebook::react::PointerEventsMode::Auto);
    }
    GetSvgNode()->UpdateCommonProps(props);
    LOG(INFO) << "[RNSVGPatternComponentInstance] x: " << props->x;
    LOG(INFO) << "[RNSVGPatternComponentInstance] y: " << props->y;
    LOG(INFO) << "[RNSVGPatternComponentInstance] width: " << props->width;
    LOG(INFO) << "[RNSVGPatternComponentInstance] height: " << props->height;
    LOG(INFO) << "[RNSVGPatternComponentInstance] patternUnits: " << props->patternUnits;
    LOG(INFO) << "[RNSVGPatternComponentInstance] patternContentUnits: " << props->patternContentUnits;
    LOG(INFO) << "[RNSVGPatternComponentInstance] minX: " << props->minX;
    LOG(INFO) << "[RNSVGPatternComponentInstance] minY: " << props->minY;
    LOG(INFO) << "[RNSVGPatternComponentInstance] vbWidth: " << props->vbWidth;
    LOG(INFO) << "[RNSVGPatternComponentInstance] vbHeight: " << props->vbHeight;
    // set attribute to svgPattern
    auto svgPattern = std::dynamic_pointer_cast<SvgPattern>(GetSvgNode());
    svgPattern->setPatternX(StringUtils::FromString(props->x));
    svgPattern->setPatternY(StringUtils::FromString(props->y));
    svgPattern->setWidth(StringUtils::FromString(props->width));
    svgPattern->setHeight(StringUtils::FromString(props->height));
    svgPattern->setPatternUnits(props->patternUnits);
    svgPattern->setPatternContentUnits(props->patternContentUnits);
    svgPattern->setViewBox(Rect(props->minX, props->minY, props->vbWidth, props->vbHeight));
    svgPattern->setmMinX(props->minX);
    svgPattern->setmMinY(props->minY);
    svgPattern->setmVbWidth(props->vbWidth);
    svgPattern->setmVbHeight(props->vbHeight);
    svgPattern->setmAlign(props->align);
    svgPattern->setmMeetOrSlice(props->meetOrSlice);
    svgPattern->setPatternTransforms(props->patternTransform);
}

SvgArkUINode &RNSVGPatternComponentInstance::getLocalRootArkUINode() { return m_svgArkUINode; }

} // namespace rnoh
