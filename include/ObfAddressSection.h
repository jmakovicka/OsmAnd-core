/**
* @file
*
* @section LICENSE
*
* OsmAnd - Android navigation software based on OSM maps.
* Copyright (C) 2010-2013  OsmAnd Authors listed in AUTHORS file
*
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.

* You should have received a copy of the GNU General Public License
* along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef __OBF_ADDRESS_REGION_SECTION_H_
#define __OBF_ADDRESS_REGION_SECTION_H_

#include <OsmAndCore.h>
#include <memory>
#include <list>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <tuple>
#include <string>
#include <google/protobuf/io/coded_stream.h>
#include <ObfSection.h>
#include <OBF.pb.h>

namespace OsmAnd {

    namespace gpb = google::protobuf;

    /**
    'Address' section of OsmAnd Binary File
    */
    struct OSMAND_CORE_API ObfAddressSection : public ObfSection
    {
        struct OSMAND_CORE_API AddressBlock : public ObfSection
        {
            typedef OBF::OsmAndAddressIndex_CitiesIndex_CitiesType Type;

            AddressBlock();
            virtual ~AddressBlock();

            Type _type;
        protected:
            static void read(gpb::io::CodedInputStream* cis, AddressBlock* section);

        private:

        friend struct ObfAddressSection;
        };

        ObfAddressSection();
        virtual ~ObfAddressSection();

        //! ???
        std::string _enName;
        
        //! ???
        int _indexNameOffset;

        std::list< std::shared_ptr<AddressBlock> > _blocks;
        
        //LatLon calculatedCenter = null;

        //public std::list< std::shared_ptr<AbstractCity> > loadCities()
    protected:
        static void read(gpb::io::CodedInputStream* cis, ObfAddressSection* section);
//        static std::list< std::shared_ptr<AbstractCity> > readCities(ObfAddressSection* section, Entry::Type type);

    private:

    friend class ObfReader;
    };

} // namespace OsmAnd

#endif // __OBF_ADDRESS_REGION_SECTION_H_