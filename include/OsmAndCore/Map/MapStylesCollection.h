#ifndef _OSMAND_CORE_MAP_STYLES_COLLECTION_H_
#define _OSMAND_CORE_MAP_STYLES_COLLECTION_H_

#include <OsmAndCore/stdlib_common.h>

#include <OsmAndCore/QtExtensions.h>
#include <QString>

#include <OsmAndCore.h>
#include <OsmAndCore/PrivateImplementation.h>
#include <OsmAndCore/Map/IMapStylesCollection.h>

namespace OsmAnd
{
    class MapStylesCollection_P;
    class OSMAND_CORE_API MapStylesCollection : public IMapStylesCollection
    {
        Q_DISABLE_COPY(MapStylesCollection);
    private:
        PrivateImplementation<MapStylesCollection_P> _p;
    protected:
    public:
        MapStylesCollection();
        virtual ~MapStylesCollection();

        bool registerStyle(const QString& filePath);

        virtual QHash< QString, std::shared_ptr<const MapStyle> > getCollection() const;
        virtual bool obtainBakedStyle(const QString& name, std::shared_ptr<const MapStyle>& outStyle) const;
    };
}

#endif // !defined(_OSMAND_CORE_MAP_STYLES_COLLECTION_H_)