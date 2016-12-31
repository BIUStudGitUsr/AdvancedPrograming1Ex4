/*
* Partners :
* Names  : Efraim Vagner and Avi Kadria
* Id (Avi)    : 211991401
* Id (Efraim) : 207304262
*/

#ifndef _H_GURD_CAB
#define _H_GURD_CAB

class Cab 
{

public:
	
	typedef enum Color{RED,BLUE,GREEN,PINK,WHITE} Color;
	
	typedef enum Manufactor {HONDA,SUBARO,TESLA,FIAT} Manufactor;

private:
	
	unsigned int m_kmp;
	
	unsigned int m_id;
	
	Manufactor m_manufactor;
	
	Color m_color;

public:
	
	unsigned int GetKMP() const { return m_kmp; }
	
	unsigned int GetID() const { return m_id; }
	
	Manufactor GetManufactor() const { return m_manufactor; }

	Color GetColor() const { return m_color; }

	void SetKMP(unsigned int ui) { m_kmp = ui; }

	void SetID(unsigned int str) { m_id = str; }

	void SetManufactor(Manufactor m) { m_manufactor = m; }

	void SetColor(Color c) { m_color = c; }

	Cab();
	
	virtual ~Cab();

};

#endif /* _H_GURD_CAB */
