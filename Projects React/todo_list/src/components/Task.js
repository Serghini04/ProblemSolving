import React from 'react';
import {
  Card,
  CardContent,
  Typography,
  IconButton,
  Box,
  Chip
} from '@mui/material';
import {
  Delete as DeleteIcon,
  Edit as EditIcon,
  Done as DoneIcon
} from '@mui/icons-material';

export default function Task({ title, deadline = "" }) {
    const handleDone = () => {
        console.log('Task completed:', title);
    };

    const handleEdit = () => {
        console.log('Edit task:', title);
    };

    const handleDelete = () => {
        console.log('Delete task:', title);
    };

    return (
        <Card 
            variant="outlined"
            sx={{
                backgroundColor: '#455fd9',
                borderRadius: 2,
                border: '2px solid #455fd9',
                cursor: 'pointer',
                transition: 'all 0.3s ease',
                '&:hover': {
                    transform: 'scale(1.02)',
                    boxShadow: '0 8px 25px rgba(69, 95, 217, 0.3)',
                    backgroundColor: '#5a6fd9'
                }
            }}
        >
            <CardContent sx={{ padding: '12px !important' }}>
                <Box 
                    display="flex" 
                    justifyContent="space-between" 
                    alignItems="center"
                    width="100%"
                >
                    <Box flex={1}>
                        <Typography 
                            variant="h6" 
                            component="h3"
                            sx={{ 
                                color: 'white',
                                fontSize: '1rem',
                                fontWeight: 'medium',
                                marginBottom: 0.5
                            }}
                        >
                            {title}
                        </Typography>
                        
                        {deadline && (
                            <Chip
                                label={deadline}
                                size="small"
                                sx={{
                                    backgroundColor: 'rgba(255, 255, 255, 0.2)',
                                    color: 'white',
                                    fontSize: '0.75rem'
                                }}
                            />
                        )}
                    </Box>

                    <Box display="flex" gap={0.5}>
                        {[
                            { icon: DoneIcon, color: '#4CAF50', onClick: handleDone, label: 'mark as done' },
                            { icon: EditIcon, color: '#2196F3', onClick: handleEdit, label: 'edit task' },
                            { icon: DeleteIcon, color: '#f44336', onClick: handleDelete, label: 'delete task' }
                        ].map(({ icon: Icon, color, onClick, label }, index) => (
                            <IconButton
                                key={index}
                                onClick={onClick}
                                size="small"
                                sx={{
                                    backgroundColor: 'white',
                                    color: color,
                                    border: `2px solid ${color}`,
                                    width: 32,
                                    height: 32,
                                    '&:hover': { backgroundColor: color, color: 'white' }
                                }}
                                aria-label={label}
                            >
                                <Icon fontSize="small" />
                            </IconButton>
                        ))}
                    </Box>
                </Box>
            </CardContent>
        </Card>
    );
}