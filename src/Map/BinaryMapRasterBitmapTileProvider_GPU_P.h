#ifndef _OSMAND_CORE_BINARY_MAP_RASTER_BITMAP_TILE_PROVIDER_GPU_P_H_
#define _OSMAND_CORE_BINARY_MAP_RASTER_BITMAP_TILE_PROVIDER_GPU_P_H_

#include "stdlib_common.h"
#include <functional>
#include <array>

#include "QtExtensions.h"

#include "OsmAndCore.h"
#include "CommonTypes.h"
#include "PrivateImplementation.h"
#include "IMapRasterBitmapTileProvider.h"
#include "BinaryMapRasterBitmapTileProvider_P.h"

class SkBitmap;

namespace OsmAnd
{
    class BinaryMapDataTile;

    class BinaryMapRasterBitmapTileProvider_GPU;
    class BinaryMapRasterBitmapTileProvider_GPU_P : public BinaryMapRasterBitmapTileProvider_P
    {
    private:
    protected:
        BinaryMapRasterBitmapTileProvider_GPU_P(BinaryMapRasterBitmapTileProvider_GPU* owner);
    public:
        virtual ~BinaryMapRasterBitmapTileProvider_GPU_P();

        ImplementationInterface<BinaryMapRasterBitmapTileProvider_GPU> owner;

        virtual bool obtainData(
            const TileId tileId,
            const ZoomLevel zoom,
            std::shared_ptr<const MapTiledData>& outTiledData,
            const IQueryController* const queryController);

    friend class OsmAnd::BinaryMapRasterBitmapTileProvider_GPU;
    };
}

#endif // !defined(_OSMAND_CORE_BINARY_MAP_RASTER_BITMAP_TILE_PROVIDER_GPU_P_H_)