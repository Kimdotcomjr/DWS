#include "BaseFixer.h"


namespace NULLPTR {
	namespace DWS {
		namespace Kernel {
			BaseFixer::BaseFixer(BaseFixer * _cl)
				:m_className(to_string(typeid(*this).name())),
				m_applyed(false)
			{
				//�������� �� ������������ �� �����
				bool isUnique = true;
				for (BaseFixer* _fixer : m_all)
				{
					if (_fixer->m_className == _cl->m_className)
					{
						isUnique = false;
						Kernel::wcerr() << "Duplicate Fixers!!! ::: " << _cl->m_className;
						break;
					}
				}
				//���� �� ��������� ����� �� ��� - � ��� � ���� ���� ������, � �� �� ����� ��������� ������ � ������. � ���� ���� - �� � ���� ���. �������.
				if (isUnique)
					m_all.push_back(_cl);
			}
			void BaseFixer::init()
			{
				Kernel::wcerr() << "Implement me virtual !!!" << __FUNCTION__ << m_className;
			}
			DllExport std::list<BaseFixer*>& BaseFixer::getAllFixers()
			{
				return m_all;
			}
			DllExport BaseFixer * BaseFixer::getFixerFromName(String _name)
			{
				BaseFixer* finded = nullptr;
				for (BaseFixer* _ptr : m_all)
				{
					if (_ptr->m_className == _name)
					{
						finded = _ptr;
						break;
					}
				}
				return finded;
			}
		}
	}
}