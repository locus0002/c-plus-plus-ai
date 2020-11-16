class BaseGameEntity {
    private:
        int m_ID;
        static int m_iNextValidID;
        void setId(int val);
    public:
        BaseGameEntity(int id) { setId(id); }
        virtual ~BaseGameEntity() {}
        virtual void update() = 0;
        int ID()const {return m_ID; }
};