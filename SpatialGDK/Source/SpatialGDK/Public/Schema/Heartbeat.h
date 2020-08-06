// Copyright (c) Improbable Worlds Ltd, All Rights Reserved

#pragma once

#include "Schema/Component.h"
#include "SpatialConstants.h"
#include "Utils/SchemaUtils.h"

#include <WorkerSDK/improbable/c_schema.h>
#include <WorkerSDK/improbable/c_worker.h>

namespace SpatialGDK
{
struct Heartbeat : Component
{
	static const Worker_ComponentId ComponentId = SpatialConstants::HEARTBEAT_COMPONENT_ID;

	Heartbeat() = default;
	Heartbeat(const Worker_ComponentData& Data) {}

	FORCEINLINE Worker_ComponentData CreateHeartbeatData()
	{
		Worker_ComponentData Data = {};
		Data.component_id = ComponentId;
		Data.schema_type = Schema_CreateComponentData();
		Schema_Object* ComponentObject = Schema_GetComponentDataFields(Data.schema_type);

		Schema_AddBool(ComponentObject, SpatialConstants::HEARTBEAT_CLIENT_HAS_QUIT_ID, false);

		return Data;
	}
};

} // namespace SpatialGDK
