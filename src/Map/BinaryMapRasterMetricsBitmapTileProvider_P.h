#ifndef _OSMAND_CORE_BINARY_MAP_RASTER_METRICS_BITMAP_TILE_PROVIDER_P_H_
#define _OSMAND_CORE_BINARY_MAP_RASTER_METRICS_BITMAP_TILE_PROVIDER_P_H_

#include "stdlib_common.h"
#include <functional>
#include <array>

#include "QtExtensions.h"
#include <QMutex>
#include <QSet>

#include "OsmAndCore.h"
#include "CommonTypes.h"
#include "PrivateImplementation.h"
#include "IMapRasterBitmapTileProvider.h"

namespace OsmAnd
{
    class BinaryMapRasterMetricsBitmapTileProvider;
    class BinaryMapRasterMetricsBitmapTileProvider_P Q_DECL_FINAL
    {
        Q_DISABLE_COPY(BinaryMapRasterMetricsBitmapTileProvider_P);
    private:
    protected:
        BinaryMapRasterMetricsBitmapTileProvider_P(BinaryMapRasterMetricsBitmapTileProvider* const owner);
    public:
        ~BinaryMapRasterMetricsBitmapTileProvider_P();

        ImplementationInterface<BinaryMapRasterMetricsBitmapTileProvider> owner;

        bool obtainData(
            const TileId tileId,
            const ZoomLevel zoom,
            std::shared_ptr<MapTiledData>& outTiledData,
            const IQueryController* const queryController);

        ZoomLevel getMinZoom() const;
        ZoomLevel getMaxZoom() const;

    friend class OsmAnd::BinaryMapRasterMetricsBitmapTileProvider;
    };
}

#endif // !defined(_OSMAND_CORE_BINARY_MAP_RASTER_METRICS_BITMAP_TILE_PROVIDER_P_H_)
