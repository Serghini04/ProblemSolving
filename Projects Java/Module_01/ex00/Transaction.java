package Module_01.ex00;

import java.util.UUID;

public class Transaction
{
	UUID	ID;
	User	recipient; // User type;
	User	send; // User type;
	String	transferCategory; // debits ,ceredits
	int		amount;
	
	public	Transaction(User recipient, User send, String transferCategory, int amount)
	{
		this.ID = UUID.randomUUID();
		this.recipient = recipient;
		this.send = send;
		this.transferCategory = transferCategory;
		this.amount = amount;
	}
	public	Transaction()
	{
		this.ID = UUID.randomUUID();
	}

    // Getters
    public UUID getID()
	{
        return ID;
    }

    public User getRecipient()
	{
        return recipient;
    }

    public User getSend()
	{
        return send;
    }

	public String getTransferCategory()
	{
		return transferCategory;
	}

	public int getAmount()
	{
		return amount;
	}

	// Setters
	public void setAmount(int amount)
	{
		this.amount = amount;
	}

    public void setRecipient(User recipient)
	{
		this.recipient = recipient;
    }

    public void setSend(User send)
	{
        this.send = send;
    }

	public void setTransferCategory(String transferCategory)
	{
		this.transferCategory = transferCategory;
	}

	public boolean startTransaction()
	{
		if (send.getBalance() - amount < 0)
			return false;
		send.setBalance(send.getBalance() - amount);
		recipient.setBalance(recipient.getBalance() + amount);
		return true;
	}
}
