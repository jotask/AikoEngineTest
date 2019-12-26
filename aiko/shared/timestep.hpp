#pragma once

namespace aiko
{

    class TimeStep
    {
    public:
        TimeStep();
        ~TimeStep() = default;

        float       getStartTime() const;
        float       getFPS() const;
        float       getDelta() const;

    private:

        // Let the Engine class have full access to this class
        friend class Engine;

        void        init();
        void        update();

        int         m_frames = 0;
        float       m_fps   = 60.0f;

        float        m_delta;
        float        m_curFPS;
        double       m_startTime;

    };

}
