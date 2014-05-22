#ifndef _OSMAND_CORE_OFFLINE_MAP_SYMBOL_PROVIDER_H_
#define _OSMAND_CORE_OFFLINE_MAP_SYMBOL_PROVIDER_H_

#include <OsmAndCore/stdlib_common.h>
#include <functional>

#include <OsmAndCore/QtExtensions.h>

#include <OsmAndCore.h>
#include <OsmAndCore/CommonTypes.h>
#include <OsmAndCore/PrivateImplementation.h>
#include <OsmAndCore/Map/IMapSymbolTiledProvider.h>

namespace OsmAnd
{
    class OfflineMapDataProvider;

    class OfflineMapStaticSymbolProvider_P;
    class OSMAND_CORE_API OfflineMapStaticSymbolProvider : public IMapSymbolTiledProvider
    {
        Q_DISABLE_COPY(OfflineMapStaticSymbolProvider);
    private:
        PrivateImplementation<OfflineMapStaticSymbolProvider_P> _p;
    protected:
    public:
        OfflineMapStaticSymbolProvider(const std::shared_ptr<OfflineMapDataProvider>& dataProvider);
        virtual ~OfflineMapStaticSymbolProvider();

        const std::shared_ptr<OfflineMapDataProvider> dataProvider;

        virtual bool obtainSymbols(
            const TileId tileId, const ZoomLevel zoom,
            std::shared_ptr<const MapSymbolsTile>& outTile,
            const FilterCallback filterCallback = nullptr);
    };
}

#endif // !defined(_OSMAND_CORE_OFFLINE_MAP_SYMBOL_PROVIDER_H_)