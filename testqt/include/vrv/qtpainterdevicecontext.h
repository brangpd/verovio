//
// Created by brangpd on 3/27/21.
//

#ifndef VEROVIO_INCLUDE_VRV_QTPAINTERDEVICECONTEXT_H
#define VEROVIO_INCLUDE_VRV_QTPAINTERDEVICECONTEXT_H

#include "devicecontext.h"

#include <QPainter>

namespace vrv {
class QtPainterDeviceContext : public DeviceContext {
    QPainter *m_painter;
    Point m_origin{};
public:
    explicit QtPainterDeviceContext(QPainter *qpainter = nullptr);

    void SetPainter(QPainter *p) { m_painter = p; }
    QPainter *GetPainter() const { return m_painter; }

    ClassId GetClassId() const override;

    void SetBackground(int colour, int style) override;
    void SetBackgroundImage(void *image, double opacity) override;
    void SetBackgroundMode(int mode) override;
    void SetTextForeground(int colour) override;
    void SetTextBackground(int colour) override;
    void SetLogicalOrigin(int x, int y) override;
    Point GetLogicalOrigin() override;
    void DrawSimpleBezierPath(Point *bezier) override;
    void DrawComplexBezierPath(Point *bezier1, Point *bezier2) override;
    void DrawCircle(int x, int y, int radius) override;
    void DrawEllipse(int x, int y, int width, int height) override;
    void DrawEllipticArc(int x, int y, int width, int height, double start, double end) override;
    void DrawLine(int x1, int y1, int x2, int y2) override;
    void DrawPolygon(int n, Point *points, int xoffset, int yoffset, int fill_style) override;
    void DrawRectangle(int x, int y, int width, int height) override;
    void DrawRotatedText(const std::string &text, int x, int y, double angle) override;
    void DrawRoundedRectangle(int x, int y, int width, int height, int radius) override;
    void DrawText(const std::string &text, const std::wstring wtext, int x, int y, int width, int height) override;
    void DrawMusicText(const std::wstring &text, int x, int y, bool setSmuflGlyph) override;
    void DrawSpline(int n, Point *points) override;
    void DrawSvgShape(int x, int y, int width, int height, pugi::xml_node svg) override;
    void DrawBackgroundImage(int x, int y) override;
    void StartText(int x, int y, data_HORIZONTALALIGNMENT alignment) override;
    void EndText() override;
    void MoveTextTo(int x, int y, data_HORIZONTALALIGNMENT alignment) override;
    void MoveTextVerticallyTo(int y) override;
    void StartGraphic(Object *object, std::string gClass, std::string gId, bool primary, bool preprend) override;
    void EndGraphic(Object *object, View *view) override;
    void ResumeGraphic(Object *object, std::string gId) override;
    void EndResumedGraphic(Object *object, View *view) override;
    void RotateGraphic(const Point &orig, double angle) override;
    void StartPage() override;
    void EndPage() override;
};
} // namespace vrv

#endif // VEROVIO_INCLUDE_VRV_QTPAINTERDEVICECONTEXT_H
