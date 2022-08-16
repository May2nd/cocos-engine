/******************************************************************************
 * Spine Runtimes License Agreement
 * Last updated January 1, 2020. Replaces all prior versions.
 *
 * Copyright (c) 2013-2020, Esoteric Software LLC
 *
 * Integration of the Spine Runtimes into software or otherwise creating
 * derivative works of the Spine Runtimes is permitted under the terms and
 * conditions of Section 2 of the Spine Editor License Agreement:
 * http://esotericsoftware.com/spine-editor-license
 *
 * Otherwise, it is permitted to integrate the Spine Runtimes into software
 * or otherwise create derivative works of the Spine Runtimes (collectively,
 * "Products"), provided that each user of the Products must obtain their own
 * Spine Editor license and redistribution of the Products in any form must
 * include this license and copyright notice.
 *
 * THE SPINE RUNTIMES ARE PROVIDED BY ESOTERIC SOFTWARE LLC "AS IS" AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL ESOTERIC SOFTWARE LLC BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES,
 * BUSINESS INTERRUPTION, OR LOSS OF USE, DATA, OR PROFITS) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
 * THE SPINE RUNTIMES, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *****************************************************************************/

#ifndef Spine_AttachmentTimeline_h
#define Spine_AttachmentTimeline_h

#include <spine/MixBlend.h>
#include <spine/MixDirection.h>
#include <spine/SpineObject.h>
#include <spine/SpineString.h>
#include <spine/Timeline.h>
#include <spine/Vector.h>

namespace spine {

class Skeleton;
class Event;

class SP_API AttachmentTimeline : public Timeline {
    friend class SkeletonBinary;
    friend class SkeletonJson;

    RTTI_DECL

public:
    explicit AttachmentTimeline(int frameCount);

    virtual void apply(Skeleton& skeleton, float lastTime, float time, Vector<Event*>* pEvents, float alpha, MixBlend blend, MixDirection direction);

    virtual int getPropertyId();

    /// Sets the time and value of the specified keyframe.
    void setFrame(int frameIndex, float time, const String& attachmentName);

    size_t getSlotIndex();
    void setSlotIndex(size_t inValue);
    const Vector<float>& getFrames();
    const Vector<String>& getAttachmentNames();
    size_t getFrameCount();

private:
    size_t _slotIndex;
    Vector<float> _frames;
    Vector<String> _attachmentNames;
};
} // namespace spine

#endif /* Spine_AttachmentTimeline_h */