// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Interiors.h"
#include "IInteriorsMaterialFactory.h"
#include "Types.h"
#include "IdTypes.h"
#include "Lighting.h"

#include <string>

namespace Eegeo
{
    namespace Resources
    {
        namespace Interiors
        {
            class InteriorsMaterialFactory : public IInteriorsMaterialFactory, private Eegeo::NonCopyable
            {
            public:
                InteriorsMaterialFactory(Rendering::Materials::MaterialIdGenerator& materialIdGenerator,
                                         const InteriorsShader& interiorsVertexColoredShader,
                                         const Lighting::GlobalLighting& globalLighting,
                                         IInteriorsMaterialAssignmentObserver& materialAssignmentObserver);
                
                Eegeo::Rendering::Materials::IMaterial* TryCreate(const InteriorMaterialData& interiorMaterialData);
                
                
            private:
                Rendering::Materials::MaterialIdGenerator& m_materialIdGenerator;
                const InteriorsShader& m_interiorsVertexColoredShader;
                const Lighting::GlobalLighting& m_globalLighting;
                IInteriorsMaterialAssignmentObserver& m_materialAssignmentObserver;
            };
        }
    }
}