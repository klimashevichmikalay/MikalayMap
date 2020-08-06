/*#ifndef JSONCOMMAND_H
#define JSONCOMMAND_H

#include "ICommand.h"

class JsonCommand : public ICommand {
 public:
  string read(string _path) {
    std::ifstream t(COORDINATES_PATH + _path);
    if (!t) throw std::runtime_error("can no open file: " + _path);

    std::string str((std::istreambuf_iterator<char>(t)),
                    std::istreambuf_iterator<char>());
    t.close();
    return str;
  }

  void save(string _json, string _path) {
    std::ofstream out(COORDINATES_PATH + _path);
    out << _json;
    out.close();
  }

  std::vector<MultiPoint> getMultiPoints(std::string _path) override {
    std::vector<MultiPoint> result;
    string multiPointsStr = read(_path);

    rapidjson::Document document;
    document.Parse(multiPointsStr.c_str());

    const rapidjson::Value &attributes = document["MultiPoints"];
    assert(attributes.IsArray());
    for (rapidjson::Value::ConstValueIterator itr = attributes.Begin();
         itr != attributes.End(); ++itr) {
      const rapidjson::Value &attribute = *itr;

      rapidjson::StringBuffer sb;
      rapidjson::Writer<rapidjson::StringBuffer> writer(sb);
      attribute.Accept(writer);
      std::string s = sb.GetString();

      MultiPoint tp = jsonToMP(s);
      result.push_back(tp);
    }
    return result;
  }

  std::vector<MultiLineString> getMultiLineStrings(std::string _path) override {
    std::vector<MultiLineString> result;
    string multiLineStr = read(_path);

    rapidjson::Document document;
    document.Parse(multiLineStr.c_str());

    const rapidjson::Value &attributes = document["MultiLineStrings"];
    assert(attributes.IsArray());
    for (rapidjson::Value::ConstValueIterator itr = attributes.Begin();
         itr != attributes.End(); ++itr) {
      const rapidjson::Value &attribute = *itr;

      rapidjson::StringBuffer sb;
      rapidjson::Writer<rapidjson::StringBuffer> writer(sb);
      attribute.Accept(writer);
      std::string s = sb.GetString();

      MultiLineString ml = jsonToML(s);
      result.push_back(ml);
    }
    return result;
  };

  std::vector<MultiFilledPolygon> getMultiFilledPolygons(
      std::string _path) override {
    std::vector<MultiFilledPolygon> result;
    string multiPointsStr = read(_path);

    rapidjson::Document document;
    document.Parse(multiPointsStr.c_str());

    const rapidjson::Value &attributes = document["MultiFilledPolygons"];
    assert(attributes.IsArray());
    for (rapidjson::Value::ConstValueIterator itr = attributes.Begin();
         itr != attributes.End(); ++itr) {
      const rapidjson::Value &attribute = *itr;

      rapidjson::StringBuffer sb;
      rapidjson::Writer<rapidjson::StringBuffer> writer(sb);
      attribute.Accept(writer);
      std::string s = sb.GetString();

      MultiFilledPolygon tp = jsonToMFP(s);
      result.push_back(tp);
    }
    return result;
  }

  std::vector<Point> getPoints(std::string _path) override {
    std::vector<Point> result;
    string multiPointsStr = read(_path);

    rapidjson::Document document;
    document.Parse(multiPointsStr.c_str());

    const rapidjson::Value &attributes = document["Points"];
    assert(attributes.IsArray());
    for (rapidjson::Value::ConstValueIterator itr = attributes.Begin();
         itr != attributes.End(); ++itr) {
      const rapidjson::Value &attribute = *itr;

      rapidjson::StringBuffer sb;
      rapidjson::Writer<rapidjson::StringBuffer> writer(sb);
      attribute.Accept(writer);
      std::string s = sb.GetString();

      Point tp = jsonToPoint(s);
      result.push_back(tp);
    }
    return result;
  }
  std::vector<LineString> getLineStrings(std::string _path) override {
    std::vector<LineString> result;
    string multiPointsStr = read(_path);

    rapidjson::Document document;
    document.Parse(multiPointsStr.c_str());

    const rapidjson::Value &attributes = document["LineStrings"];
    assert(attributes.IsArray());
    for (rapidjson::Value::ConstValueIterator itr = attributes.Begin();
         itr != attributes.End(); ++itr) {
      const rapidjson::Value &attribute = *itr;

      rapidjson::StringBuffer sb;
      rapidjson::Writer<rapidjson::StringBuffer> writer(sb);
      attribute.Accept(writer);
      std::string s = sb.GetString();

      LineString tp = jsonToLine(s);
      result.push_back(tp);
    }
    return result;
  }
  std::vector<FilledPolygon> getFilledPolygons(std::string _path) override {
    std::vector<FilledPolygon> result;
    string multiPointsStr = read(_path);

    rapidjson::Document document;
    document.Parse(multiPointsStr.c_str());

    const rapidjson::Value &attributes = document["FilledPolygons"];
    assert(attributes.IsArray());
    for (rapidjson::Value::ConstValueIterator itr = attributes.Begin();
         itr != attributes.End(); ++itr) {
      const rapidjson::Value &attribute = *itr;

      rapidjson::StringBuffer sb;
      rapidjson::Writer<rapidjson::StringBuffer> writer(sb);
      attribute.Accept(writer);
      std::string s = sb.GetString();

      FilledPolygon tp = jsonToFP(s);
      result.push_back(tp);
    }
    return result;
  }

  void saveMultiPoints(std::vector<MultiPoint> points,
                       std::string _path) override {
    rapidjson::StringBuffer sb;
    rapidjson::PrettyWriter<rapidjson::StringBuffer> writer(sb);

    writer.StartObject();
    writer.Key("MultiPoints");
    writer.StartArray();

    for (std::vector<MultiPoint>::const_iterator itr = points.begin();
         itr != points.end(); ++itr)
      mpToJSON(*itr, writer);
    writer.EndArray();
    writer.EndObject();

    save(sb.GetString(), _path);
  }

  void saveMultiLineStrings(std::vector<MultiLineString> lines,
                            std::string _path) override {
    rapidjson::StringBuffer sb;
    rapidjson::PrettyWriter<rapidjson::StringBuffer> writer(sb);

    writer.StartObject();
    writer.Key("MultiLineStrings");
    writer.StartArray();

    for (std::vector<MultiLineString>::const_iterator itr = lines.begin();
         itr != lines.end(); ++itr)
      mlToJSON(*itr, writer);
    writer.EndArray();
    writer.EndObject();

    save(sb.GetString(), _path);
  }

  void saveMultiFilledPolygons(std::vector<MultiFilledPolygon> polygons,
                               std::string _path) override {
    rapidjson::StringBuffer sb;
    rapidjson::PrettyWriter<rapidjson::StringBuffer> writer(sb);

    writer.StartObject();
    writer.Key("MultiFilledPolygons");
    writer.StartArray();

    for (std::vector<MultiFilledPolygon>::const_iterator itr = polygons.begin();
         itr != polygons.end(); ++itr)
      mfpToJSON(*itr, writer);
    writer.EndArray();
    writer.EndObject();

    save(sb.GetString(), _path);
  }

  void savePoints(std::vector<Point> points, std::string _path) override {
    rapidjson::StringBuffer sb;
    rapidjson::PrettyWriter<rapidjson::StringBuffer> writer(sb);

    writer.StartObject();
    writer.Key("Points");
    writer.StartArray();

    for (std::vector<Point>::const_iterator itr = points.begin();
         itr != points.end(); ++itr)
      pointToJSON(*itr, writer);
    writer.EndArray();
    writer.EndObject();

    save(sb.GetString(), _path);
  }

  void saveLineStrings(std::vector<LineString> lines,
                       std::string _path) override {
    rapidjson::StringBuffer sb;
    rapidjson::PrettyWriter<rapidjson::StringBuffer> writer(sb);

    writer.StartObject();
    writer.Key("LineStrings");
    writer.StartArray();

    for (std::vector<LineString>::const_iterator itr = lines.begin();
         itr != lines.end(); ++itr)
      lineToJSON(*itr, writer);
    writer.EndArray();
    writer.EndObject();

    save(sb.GetString(), _path);
  }

  void saveFilledPolygons(std::vector<FilledPolygon> polygons,
                          std::string _path) override {
    rapidjson::StringBuffer sb;
    rapidjson::PrettyWriter<rapidjson::StringBuffer> writer(sb);

    writer.StartObject();
    writer.Key("FilledPolygons");
    writer.StartArray();

    for (std::vector<FilledPolygon>::const_iterator itr = polygons.begin();
         itr != polygons.end(); ++itr)
      lineToJSON(*itr, writer);
    writer.EndArray();
    writer.EndObject();

    save(sb.GetString(), _path);
  }
};

#endif  // JSONCOMMAND_H
*/
